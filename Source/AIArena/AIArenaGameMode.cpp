// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIArenaGameMode.h"
#include "AIArenaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIArenaGameMode::AAIArenaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
