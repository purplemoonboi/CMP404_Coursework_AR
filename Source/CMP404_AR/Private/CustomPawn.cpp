// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomPawn.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"
#include "ARBlueprintLibrary.h"


// Sets default values
ACustomPawn::ACustomPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	CameraComponent = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SceneComponent);


}

// Called when the game starts or when spawned
void ACustomPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UKismetSystemLibrary::PrintString(this, FString(TEXT("Hello world")), true, true, FLinearColor::Red, 5);

	UARSessionConfig* Config = NewObject<UARSessionConfig>();
	UARBlueprintLibrary::StartARSession(Config);
}

// Called every frame
void ACustomPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

