// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPlayerController.h"
#include "ARBlueprintLibrary.h"
#include "ARCustomPawn.h"
#include "Math/UnrealMathUtility.h"

AARPlayerController::AARPlayerController()
{
	Pawn = GetPawn<AARCustomPawn>();
}

bool AARPlayerController::AnyTouchRecieved()
{
	float X;
	
	GetInputTouchState(ETouchIndex::Touch1, X, X, bHasReceivedAnyTouch);

	GetInputTouchState(ETouchIndex::Touch2, X, X, bHasReceivedAnyTouch);
	
	return bHasReceivedAnyTouch;
}

void AARPlayerController::OneFingerGestureRecognition()
{
	if(!((bObjectIsPlaced && bOneFingerPressed && !(bGestureRecognised) && !(bTwoFingerPressed))))
	{
		OneFingerValidationTimer = 0.0f;
	}
		else
		{
			OneFingerValidationTimer += DeltaTime;

			if(OneFingerValidationTimer > 0.2f)
			{
				bGestureRecognised = true;
				CurrentTransform = ECurrentTransform::Translation;
			}
			
		}
}

void AARPlayerController::TwoFingerGestureRecognition()
{
	if(!(bObjectIsPlaced && bTwoFingerPressed && !(bGestureRecognised)))
	{
		TwoFingerValidationTimer = 0.0f;
	}
	else
	{
		TwoFingerValidationTimer += DeltaTime;
		
		if(TwoFingerValidationTimer > 0.2f)
		{
			CurrentTransform = ECurrentTransform::Translation;

			const float FingerDistanceValue = FMath::Abs((GetFingerDistance()) - PreviousFingerDistance);
			if(FMath::IsNearlyEqual(FingerDistanceValue, 0.0f))
			{
				TwoFingerValidationTimer = 0.0f;
			}
			else
			{
				bGestureRecognised = true;
				const FVector2D TouchDirection = GetFingerDirection();
				
				if(FMath::Abs(TouchDirection.Y) < 0.5f)
				{
					CurrentTransform = ECurrentTransform::Rotation;
				}
				else
				{
					CurrentTransform = ECurrentTransform::Scale;
				}

				PreviousFingerDirection = TouchDirection;
			}
		}
	}
}

void AARPlayerController::OnTouchEvent()
{
	if(TouchEv)
}

float AARPlayerController::GetFingerDistance() const
{
	bool bIsCurrentlyPressed;

	/* get finger positions */
	const FVector2D FingerPosOne = GetTouchLocation(uint8(1));
	const FVector2D FingerPosTwo = GetTouchLocation(uint8(2));
	
	return FVector2D::Distance(FingerPosOne, FingerPosTwo);
}

FVector2D AARPlayerController::GetFingerDirection(double NormalizedTolerance) const
{
	const FVector2D TouchLocation = GetTouchLocation();
	
	FVector2D TouchDirection = (PreviousFingerPosition - TouchLocation);
	TouchDirection.Normalize(NormalizedTolerance);
	
	return TouchDirection;
	
}

FVector2D AARPlayerController::GetTouchLocation(uint8 TouchIndex) const
{
	float X;
	float Y;
	bool bIsCurrentlyPressed;
	
	GetInputTouchState((ETouchIndex::Type)TouchIndex, X, Y, bIsCurrentlyPressed);

	return {X, Y};
}


