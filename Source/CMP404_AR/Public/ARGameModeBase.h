// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ARGameStateBase.h"
#include "GameFramework/GameModeBase.h"
#include "ARGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CMP404_AR_API AARGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	AARGameModeBase();
	virtual ~AARGameModeBase() = default;

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void SpawnAsset() const;
protected:



private:
	
	int32* Score;

	/* UE timer object */
	FTimerHandle Ticker;
};
