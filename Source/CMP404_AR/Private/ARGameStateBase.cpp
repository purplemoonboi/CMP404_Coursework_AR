// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGameStateBase.h"

AARGameStateBase::AARGameStateBase()
{
}

int32& AARGameStateBase::GetScore()
{
	return Score;
}

void AARGameStateBase::SetScore(int32 newScore)
{
	Score = newScore;
}
