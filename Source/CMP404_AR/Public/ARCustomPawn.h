// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ARCustomPawn.generated.h"

/** forward declarations */
class UCameraComponent;

UCLASS()
class CMP404_AR_API AARCustomPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARCustomPawn();

protected:

	/* variables exposed in editor */

	/** variables */
	UPROPERTY(Category = "SceneComponent", VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(Category = "CameraComponent", VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

protected:

	/* inherited functions */
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	/* unreal game loop functions */
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	/* public functions */

	
protected:

};
