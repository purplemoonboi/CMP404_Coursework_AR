// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorSoftBody.generated.h"

UCLASS()
class CMP404_AR_API AActorSoftBody : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorSoftBody();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	UPROPERTY(Category = "SceneComponent", VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

	UPROPERTY(Category = "StaticMeshComponent", VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION(Category = "Gameplay", BlueprintCallable)
	FVector InfinityTranslation(const float time);


private:

	// Variables that need not be exposed to the editor.
	
	double StartSeconds = 0.0f, ElapsedTime = 0.0f;

};
