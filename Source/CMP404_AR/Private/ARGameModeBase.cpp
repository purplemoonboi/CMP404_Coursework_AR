// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGameModeBase.h"
#include "ARGameStateBase.h"
#include "ActorSoftBody.h"
#include "ARCustomPawn.h"

AARGameModeBase::AARGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AARCustomPawn::StaticClass();
	GameStateClass = AARGameStateBase::StaticClass();
}

void AARGameModeBase::StartPlay()
{
	Score = &GetGameState<AARGameStateBase>()->GetScore();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
		FString::Printf(TEXT("Current Score %d"), *Score));


	GetWorldTimerManager().SetTimer(Ticker, this,&AARGameModeBase::SpawnAsset, 4.0f, true, 0.0f);

	// This function will transcend to call BeginPlay on all actors.
	Super::StartPlay();
}

void AARGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void AARGameModeBase::SpawnAsset() const
{
	const FActorSpawnParameters SpawnInfo;
	const FRotator MyRotator(0, 0, 0);
	const FVector MyVector(150, 0, -50);
	AActorSoftBody* SpawnedActor = GetWorld()->SpawnActor<AActorSoftBody>(MyVector, MyRotator, SpawnInfo);
}
