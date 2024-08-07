// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/HaloOfProtection.h"

FString UHaloOfProtection::GetDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

		return FString::Printf(TEXT(
			//Title
			"<Title>HaloOfProtection</>\n\n"

			//Levels
			"<Small>Level: </><Level> %d </>\n"

			//Description
			"<Default>Automatically creates a barrier to protect against attacks, "
			"Reduce damage by </><Damage>%1.f</><Default>%%</>"),

			//Values
			Level,
			PercentValue);
}

FString UHaloOfProtection::GetNextLevelDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

		return FString::Printf(TEXT(
			//Title
			"<Title>HaloOfProtection</>\n\n"

			//Levels
			"<Small>Level: </><Level> %d </>\n"

			//Description
			"<Default>Automatically creates a barrier to protect against attacks, "
			"Reduce damage by </><Damage>%1.f</><Default>%%</>"),

			//Values
			Level,
			PercentValue);
}