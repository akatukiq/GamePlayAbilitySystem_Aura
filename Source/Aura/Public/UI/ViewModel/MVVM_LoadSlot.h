// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Game/LoadScreenSaveGame.h"
#include "MVVM_LoadSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetWidgetSwitcherIndex, int32, WidgetSwitcherIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnableSelectSlotButton, bool, bEnable );
/**
 * 
 */
UCLASS()
class AURA_API UMVVM_LoadSlot : public UMVVMViewModelBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FSetWidgetSwitcherIndex SetWidgetSwitcherIndex;

	UPROPERTY(BlueprintAssignable)
	FEnableSelectSlotButton EnableSelectSlotButton;

	void InitializeSlot();

	void SetPlayerName(FString InPlayerName);
	void SetMapName(FString InMapName);
	void SetPlayerLevel(int32 InLevel);
	void SetLoadSlotName(FString InLoadSlotName);

	FString GetPlayerName() const { return PlayerName; }
	FString GetMapName() const { return MapName; }
	int32 GetPlayerLevel() const { return PlayerLevel; }
	FString GetLoadSlotName() const { return LoadSlotName; }

	UPROPERTY()
	int32 SlotIndex;

	UPROPERTY()
	TEnumAsByte<ESaveSlotStatus> SlotStatus;

	UPROPERTY()
	FName PlayerStartTag;

	UPROPERTY()
	FString MapAssetName;



private:

	/* Field Notifies */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, Meta = (AllowPrivateAccess = "True"));
	FString PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, Meta = (AllowPrivateAccess = "True"));
	FString MapName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, Meta = (AllowPrivateAccess = "True"));
	int32 PlayerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, FieldNotify, Setter, Getter, Meta = (AllowPrivateAccess = "True"));
	FString LoadSlotName;


};
