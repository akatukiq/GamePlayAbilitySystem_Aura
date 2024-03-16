// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/PlayerInterface.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()
	
public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewContoroller) override;
	virtual void OnRep_PlayerState() override;

	/* Players interface */
	virtual void AddToXP_Implementation(int32 InXP) override;
	virtual void LevelUp_Implementation()override;

	/* combat interface */

	virtual int32 GetPlayerLevel_Implementation() override;

	/* end combat interface */

private:
	virtual void InitAbiilityActorinfo() override;
};
