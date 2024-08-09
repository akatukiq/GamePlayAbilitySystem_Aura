// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/LifeSiphon.h"

FString ULifeSiphon::GetDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

	return FString::Printf(TEXT(
		//Title
		"<Title>LifeSiphon</>\n\n"

		//Levels
		"<Small>Level: </><Level> %d </>\n"

		//Description
		"<Default>Absorbs Health from opponent, "
		"Recover Health equal to </><Damage>%1.f</><Default>%% of damage dealt</>"),

		//Values
		Level,
		PercentValue);
}

FString ULifeSiphon::GetNextLevelDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

	return FString::Printf(TEXT(
		//Title
		"<Title>LifeSiphon</>\n\n"

		//Levels
		"<Small>Level: </><Level> %d </>\n"

		//Description
		"<Default>Absorbs Health from opponent, "
		"Recover Health equal to </><Damage>%1.f</><Default>%% of damage dealt</>"),

		//Values
		Level,
		PercentValue);
}