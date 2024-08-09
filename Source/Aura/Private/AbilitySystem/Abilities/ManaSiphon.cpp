// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/ManaSiphon.h"

FString UManaSiphon::GetDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

	return FString::Printf(TEXT(
		//Title
		"<Title>ManaSiphon</>\n\n"

		//Levels
		"<Small>Level: </><Level> %d </>\n"

		//Description
		"<Default>Absorbs Mana from opponent, "
		"Recover Mana equal to </><Damage>%1.f</><Default>%% of damage dealt</>"),

		//Values
		Level,
		PercentValue);
}

FString UManaSiphon::GetNextLevelDescription(int32 Level)
{
	const float ScaledPassiveValue = PassiveValue.GetValueAtLevel(Level);
	float PercentValue = ScaledPassiveValue * 100.f;

	return FString::Printf(TEXT(
		//Title
		"<Title>ManaSiphon</>\n\n"

		//Levels
		"<Small>Level: </><Level> %d </>\n"

		//Description
		"<Default>Absorbs Mana from opponent, "
		"Recover Mana equal to </><Damage>%1.f</><Default>%% of damage dealt</>"),

		//Values
		Level,
		PercentValue);
}