// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorSoftBody.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "ARBlueprintLibrary.h"

// Sets default values
AActorSoftBody::AActorSoftBody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/** Create a scene component (Transform component) and make it the root component */
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	
	/** Create the static mesh component and attach it to the scene component */
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneComponent);

	/** Assign the skeletal mesh asset  */
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/ProductAssets/Mesh/SM_Manequin.SM_Manequin'"));

	StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
}

// Called when the game starts or when spawned
void AActorSoftBody::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString
	(
		this,
		FString(TEXT("It's time to dance")),
		true,
		true,
		FLinearColor::Green,
		1
		);
	
	StartSeconds = FPlatformTime::Seconds();
	
}

// Called every frame
void AActorSoftBody::Tick(float DeltaTime)
{
	ElapsedTime = FPlatformTime::Seconds() - StartSeconds;
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + InfinityTranslation(ElapsedTime));
}

FVector AActorSoftBody::InfinityTranslation(const float time)
{
	const float scale = 2.f / (3.f - UKismetMathLibrary::Cos(2.f * time));
	return 
	{
		scale * UKismetMathLibrary::Cos(time), 
		scale* UKismetMathLibrary::Sin(2 * time),
		0.0f
	};
}

