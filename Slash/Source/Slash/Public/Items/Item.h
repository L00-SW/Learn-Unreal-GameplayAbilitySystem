// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Sine")
	float TransformdSin();

	template<typename T>
	T Avg(T First, T Second);

private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime = 0;

	UPROPERTY(EditAnywhere, Category = "Sine")
	float Amplitude = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Sine")
	float TimeConstant = 5.f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere)
	float RollSpeed;
};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
