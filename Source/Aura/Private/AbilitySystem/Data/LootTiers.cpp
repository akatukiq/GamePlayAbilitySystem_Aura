// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/LootTiers.h"

TArray<FLootItem> ULootTiers::GetLootImtes()
{
	TArray<FLootItem> ReturnItems;
	for (FLootItem& Item : LootItems)
	{
		for (int32 i = 0; i < Item.MaxNumberToSpawn; ++i)
		{
			if (FMath::RandRange(1, 100) < Item.ChanceToSpawn)
			{
				FLootItem NewItem;
				NewItem.LootClass = Item.LootClass;
				NewItem.bLootLevelOverride = Item.bLootLevelOverride;
				ReturnItems.Add(NewItem);
			}
		}
	}

	return ReturnItems;
}
