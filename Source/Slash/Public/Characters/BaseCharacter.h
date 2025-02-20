// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"

class AWeapon;
class UAttributeComponent;
class UAnimMontage;



UCLASS()
class SLASH_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	//Combat
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void LightAttack();
	void DirectionalHitReact(const FVector& ImpactPoint);
	virtual void HandleDamage(float DamageAmount);
	void PlayHitSound(const FVector &ImpactPoint);
	void SpawnHitParticles(const FVector &ImpactPoint);
	void DisableCapsule();
	virtual bool CanAttack();
	bool IsAlive();
	void DisableMeshCollisioin();

	//Play montage functions
	void PlayHitReactMontage(const FName& SectionName);
	virtual void PlayDeathMontage();
	void PlayComboAttackMontage();
	void PlayRandomAttackMontage();
	void PlayRandomDeathMontage();
	virtual void PlayDodgeMontage();
	void StopAttackMotage();

	UFUNCTION(BlueprintCallable)
	FVector GetTranslationWarpTarget();

	UFUNCTION(BlueprintCallable)
	FVector GetRotationWarpTarget();

	//Blueprint Notify Check Functions
	UFUNCTION(BlueprintCallable)
	virtual void ResetAttack();

	UFUNCTION(BlueprintCallable)
	virtual void DodgeEnd();

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);


	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EqippedWeapon;

	//Components
	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes;

	//Combo Attack Variable
	UPROPERTY(BlueprintReadOnly)
	int32 AttackIndex = 0;

	UPROPERTY()
	bool bResetCombo = true;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	AActor* CombatTarget;

	UPROPERTY(EditAnywhere, Category = "Combat")
	double WarpTargetDistance = 75.f;


private:
	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	void PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);

	//SFX
	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystem* HitParticle;

	/*
	Animation Montage
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* DeathMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* DodgeMontage;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FName> AttackMontageSections;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FName> DeathMontageSections;
};
