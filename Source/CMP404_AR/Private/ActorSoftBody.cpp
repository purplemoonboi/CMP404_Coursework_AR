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

void AActorSoftBody::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	/** after initialising the actor, store it's position on spawn */
	ActorSpawnLoc = GetActorLocation();
}

// Called every frame
void AActorSoftBody::Tick(float DeltaTime)
{
	// Calculate the elapsed time since the actor has been spawned
	ElapsedTime = FPlatformTime::Seconds() - StartSeconds;
	Super::Tick(DeltaTime);
	
	//SetActorLocation(GetActorLocation() + InfinityTranslation(ElapsedTime));
	FMatrix TranslationMatrix = FMatrix::Identity;
	FMatrix InitialMatrix = FMatrix::Identity;
	FMatrix FinalMatrix = FMatrix::Identity;
	const FVector newPos =  InfinityTranslation(ElapsedTime);

	// Store the initial spawn location
	InitialMatrix = InitTranslationMatrix(ActorSpawnLoc);
	TranslationMatrix = InitTranslationMatrix(newPos);

	FinalMatrix = TranslationMatrix * InitialMatrix;
	SetActorTransform(FTransform(FinalMatrix));

}

FVector AActorSoftBody::InfinityTranslation(const float Time)
{
	const float scale = 2.f / (3.f - UKismetMathLibrary::Cos(2.f * Time));
	return 
	{
		scale * UKismetMathLibrary::Cos(Time), 
		scale* UKismetMathLibrary::Sin(2 * Time),
		0.0f
	};
}

FMatrix AActorSoftBody::InitTranslationMatrix(const float X, const float Y, const float Z)
{
	FMatrix matrix = FMatrix::Identity;
	matrix.M[3][0] = X;
	matrix.M[3][1] = Y;
	matrix.M[3][2] = Z;

	return matrix;
}

FMatrix AActorSoftBody::InitTranslationMatrix(FVector Vector)
{
	return InitTranslationMatrix(Vector.X, Vector.Y, Vector.Z);
}

