// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"

#include "Behaviortree/BlackboardComponent.h"
#include "Behaviortree/Blackboard/BlackboardKeyType_Vector.h"

#include "Blackboard_keys.h"

#include "NPC_AIController.h"

#include "Runtime/NavigationSystem/Public/NavigationSystem.h"




UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get AI controller & NPC
	auto const Controller = Cast<ANPC_AIController>(OwnerComp.GetAIOwner());
	auto const NPC = Controller->GetPawn();

	// Obtain NPC location to use as origin
	FVector const Origin = NPC->GetActorLocation();
	FNavLocation Location;

	// Get Navigation system and generate a random location in Navmesh
	UNavigationSystemV1* const NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavigationSystem->GetRandomPointInNavigableRadius(Origin, searh_radius, Location, nullptr))
	{
		Controller->get_blackboard()->SetValueAsVector(BB_Keys::target_location, Location.Location);
	}

	//Finish with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
