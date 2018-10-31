// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "GameFramework/Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn *InstigatorPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("Complete Mission"));
	if (InstigatorPawn != nullptr)
	{
		InstigatorPawn->DisableInput(nullptr);
	}
	UGameplayStatics::PlaySound2D(this, GameCompleteSound);
	OnMissionCompleted(InstigatorPawn);
}

