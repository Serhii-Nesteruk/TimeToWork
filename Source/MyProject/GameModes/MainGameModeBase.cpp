// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "MainGameModeBase.h"

AMainGameModeBase::AMainGameModeBase() : GameController(nullptr)
{
	PlayerControllerClass = AGameController::StaticClass(); 
}

void AMainGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GameController = Cast<AGameController>(GetWorld()->GetFirstPlayerController());
	if (GameController)
	{
		// GameController->InitializeSprites();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameController not found"));
	}
}
