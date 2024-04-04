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

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);



protected:
	virtual void BeginPlay() override;

	virtual void LightAttack();

	/*
	Play montage functions
	*/
	void PlayHitReactMontage(const FName& SectionName);
	virtual void PlayDeathMontage();
	void DirectionalHitReact(const FVector& ImpactPoint);
	void PlayHitSound(const FVector &ImpactPoint);
	void SpawnHitParticles(const FVector &ImpactPoint);
	virtual void HandleDamage(float DamageAmount);
	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	void PlayComboAttackMontage();
	void PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);
	void PlayRandomAttackMontage();
	void PlayRandomDeathMontage();
	void DisableCapsule();

	virtual bool CanAttack();
	bool IsAlive();

	//Blueprint Notify Check Functions
	UFUNCTION(BlueprintCallable)
	virtual void ResetAttack();

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EqippedWeapon;

	/*
	Animation Montage
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FName> AttackMontageSections;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TArray<FName> DeathMontageSections;

	//Components
	UPROPERTY(VisibleAnywhere)
	UAttributeComponent* Attributes;

	//Combo Attack Variable
	UPROPERTY(BlueprintReadOnly)
	int32 AttackIndex = 0;

	UPROPERTY()
	bool bResetCombo = true;


private:
	//SFX
	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "VisualEffect")
	UParticleSystem* HitParticle;
};
