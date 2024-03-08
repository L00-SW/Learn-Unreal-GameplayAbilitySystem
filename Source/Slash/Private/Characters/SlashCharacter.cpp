// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GroomComponent.h"
#include "Items/Item.h"
#include "Items/Weapons/Weapon.h"


ASlashCharacter::ASlashCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	Hair->AttachmentName = FString("head");

	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(GetMesh());
	Eyebrows->AttachmentName = FString("head");
}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(SlashMappingContext, 0);
		}
	}
}

void ASlashCharacter::Move(const FInputActionValue& Value)
{
	if (ActionState != EActionState::EAS_Unoccupied || bResetCombo == false) return;

	const FVector2D MovementVector = Value.Get<FVector2D>();

	//find out which way is forward
	const FRotator ControlRotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementVector.Y);
	//find out which way is right
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void ASlashCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxis.X);
	AddControllerPitchInput(LookAxis.Y);
}

void ASlashCharacter::EquipInput()
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(OverlappingItem);
	if (OverlappingWeapon)
	{
		OverlappingWeapon->Equip(GetMesh(), FName("RightHandSocket"));
		CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
		OverlappingItem = nullptr;
		EqippedWeapon = OverlappingWeapon;
	}
	else
	{
		if (CanDisarm())
		{
			PlayEquipMontage(FName("Disarm_Shoulder"));
			CharacterState = ECharacterState::ECS_Unequipped;
			ActionState = EActionState::EAS_Equipping;
		}
		else if (CanArm())
		{
			PlayEquipMontage(FName("Equip_Shoulder"));
			CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
			ActionState = EActionState::EAS_Equipping;
		}
	}
}

void ASlashCharacter::LMBAttack()
{
	if (CanAttack())
	{
		ActionState = EActionState::EAS_Attacking;

		PlayAttackMontage();
	}
}

void ASlashCharacter::PlayAttackMontage()
{
	UAnimInstance* Animinstance = GetMesh()->GetAnimInstance();
	if (Animinstance && AttackMontage)
	{
		Animinstance->Montage_Play(AttackMontage);
		FName AttackName = FName();
		switch (AttackIndex) {
		case 0:
			++AttackIndex;
			AttackName = FName("Attack1");
			break;
		case 1:
			AttackIndex = 0;
			AttackName = FName("Attack2");
			break;
		default:
			break;
		}
		bResetCombo = false;
		Animinstance->Montage_JumpToSection(AttackName, AttackMontage);
	}
}

void ASlashCharacter::PlayEquipMontage(FName SectionName)
{
	UAnimInstance* Animinstance = GetMesh()->GetAnimInstance();
	if (Animinstance && EquipShoulderMontage)
	{
		Animinstance->Montage_Play(EquipShoulderMontage);
		Animinstance->Montage_JumpToSection(SectionName, EquipShoulderMontage);
	}
}

void ASlashCharacter::ResetAttack()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void ASlashCharacter::ResetCombo()
{
	AttackIndex = 0;
	bResetCombo = true;
}

bool ASlashCharacter::CanAttack()
{
	return CharacterState != ECharacterState::ECS_Unequipped &&
		ActionState != EActionState::EAS_Attacking;
}

bool ASlashCharacter::CanDisarm()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState != ECharacterState::ECS_Unequipped &&
		bResetCombo == true;
}

bool ASlashCharacter::CanArm()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState == ECharacterState::ECS_Unequipped &&
		bResetCombo == true &&
		EqippedWeapon;
}

void ASlashCharacter::Disarm()
{
	if (EqippedWeapon)
	{
		EqippedWeapon->AttachMeshToSocket(GetMesh(), FName("SpineSocket"));
	}
}

void ASlashCharacter::Equip_Shoulder()
{
	if (EqippedWeapon)
	{
		EqippedWeapon->AttachMeshToSocket(GetMesh(), FName("RightHandSocket"));
	}
}

void ASlashCharacter::FinishEquipping()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASlashCharacter::Jump);
		EnhancedInputComponent->BindAction(EquipAction, ETriggerEvent::Started, this, &ASlashCharacter::EquipInput);
		EnhancedInputComponent->BindAction(LMBAction, ETriggerEvent::Started, this, &ASlashCharacter::LMBAttack);
	}

}

void ASlashCharacter::Jump()
{
	Super::Jump();
}

