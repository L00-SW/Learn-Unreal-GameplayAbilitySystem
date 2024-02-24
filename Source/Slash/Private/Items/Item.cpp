// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"
#include "Slash/DebugMacro.h"
#include "Components/SphereComponent.h"


AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::SphereBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::SphereEndOverlap);
}

float AItem::TransformdSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

void AItem::SphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Blue, OtherActorName);
	}
}

void AItem::SphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherCompName = OtherComp->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 30.f, FColor::Blue, OtherCompName);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	RollSpeed = TransformdSin();

	AddActorWorldRotation(FRotator(RollSpeed, 0.f, 0.f));
}
