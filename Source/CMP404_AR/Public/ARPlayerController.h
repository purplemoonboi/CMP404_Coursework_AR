// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ARPlayerController.generated.h"

class AARCustomPawn;

UENUM()
enum class ECurrentTransform
{
	Translation = 0,
	Rotation,
	Scale
};

/**
 * 
 */
UCLASS()
class CMP404_AR_API AARPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	AARPlayerController();
	virtual ~AARPlayerController() = default;

	
	UFUNCTION(Category = "Input", BlueprintCallable)
	bool ObjectIsPlaced() const { return bObjectIsPlaced; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	bool HasOneFingerPressed() const { return bOneFingerPressed; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	bool IsGestureRecognised() const { return bGestureRecognised; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	bool HasTwoFingersPressed() const { return bTwoFingerPressed; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	float GetOneFingerValidationTimer() const { return OneFingerValidationTimer; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	float GetTwoFingerValidationTimer() const { return TwoFingerValidationTimer; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	float GetPreviousFingerDistance() const { return PreviousFingerDistance; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	FVector2D GetPreviousTouchPosition() const { return PreviousFingerPosition; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	FVector2D GetPreviousFingerDirection() const { return PreviousFingerDirection; }

	UFUNCTION(Category = "Input", BlueprintCallable)
	bool AnyTouchRecieved();

protected:

	UFUNCTION(Category = "Input", BlueprintCallable)
	void OneFingerGestureRecognition();

	UFUNCTION(Category = "Input", BlueprintCallable)
	void TwoFingerGestureRecognition();

	UFUNCTION(Category = "Input", BlueprintCallable)
	void OnTouchEvent();

	UFUNCTION(Category = "Input", BlueprintCallable)
	float GetFingerDistance() const;

	UFUNCTION(Category = "Input", BlueprintCallable)
	FVector2D GetFingerDirection(double NormalizedTolerance = 0.01) const;

	UFUNCTION(Category = "Input", BlueprintCallable)
	FVector2D GetTouchLocation(uint8 TouchIndex = 1) const;

protected:

	/* variables tracking input states from user */
	UPROPERTY(Category = "Player", VisibleAnywhere, BlueprintReadOnly)
	AARCustomPawn* Pawn;
	
	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	bool bObjectIsPlaced;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	bool bOneFingerPressed;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	bool bGestureRecognised;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	bool bTwoFingerPressed;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	bool bHasReceivedAnyTouch;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	float OneFingerValidationTimer;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	float TwoFingerValidationTimer;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	float PreviousFingerDistance;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	FVector2D PreviousFingerPosition;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	FVector2D PreviousFingerDirection;

	UPROPERTY(Category = "Input", VisibleAnywhere, BlueprintReadOnly)
	ECurrentTransform CurrentTransform;
	
	/* hidden variables */

	
	float DeltaTime;
};
