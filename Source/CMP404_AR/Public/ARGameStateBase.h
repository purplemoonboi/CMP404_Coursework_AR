// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ARGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CMP404_AR_API AARGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:

	AARGameStateBase();
	virtual ~AARGameStateBase() = default;
	

	UFUNCTION(BlueprintCallable, Category = "Score")
	int32& GetScore();

	UFUNCTION(BlueprintCallable, Category = "Score")
	void SetScore(int32 newScore);

private:

	int32 Score;
	
};
