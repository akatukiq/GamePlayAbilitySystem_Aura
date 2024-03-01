// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_FindNearesPlayer.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

void UBTService_FindNearesPlayer::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaSecond)
{
	Super::TickNode(OwnerComponent, NodeMemory, DeltaSecond);

	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, *AIOwner->GetName());
	GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Green, *ActorOwner->GetName());

	APawn* OwningPawn = AIOwner->GetPawn();

	const FName TargetTag = OwningPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");

	TArray<AActor*> ActorWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, ActorWithTag);
}
