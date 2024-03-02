// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_FindNearesPlayer.h"
#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UBTService_FindNearesPlayer::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaSecond)
{
	Super::TickNode(OwnerComponent, NodeMemory, DeltaSecond);

	APawn* OwningPawn = AIOwner->GetPawn();

	const FName TargetTag = OwningPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");

	TArray<AActor*> ActorWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwningPawn, TargetTag, ActorWithTag);

	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* ClosestActor = nullptr;
	for (AActor* Actor : ActorWithTag)
	{		
		if (IsValid(Actor) && IsValid(OwningPawn))
		{
			const float Distance = OwningPawn->GetDistanceTo(Actor);
			if (Distance <ClosestDistance)
			{
				ClosestDistance = Distance;
				ClosestActor = Actor;
			}
		}
	}
	UBTFunctionLibrary::SetBlackboardValueAsObject(this, TargetToFollowSelector, ClosestActor);
	UBTFunctionLibrary::SetBlackboardValueAsFloat(this, DistanceToTargetSelector, ClosestDistance);
}
