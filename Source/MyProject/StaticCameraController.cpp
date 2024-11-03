// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticCameraController.h"

#include "MainCameraActor.h"
#include "Kismet/GameplayStatics.h"

AStaticCameraController::AStaticCameraController()
{
	
}

void AStaticCameraController::BeginPlay()
{
	Super::BeginPlay();

	ACameraActor* cameraActor =
		Cast<ACameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AMainCameraActor::StaticClass()));
	if (cameraActor)
	{
		SetViewTarget(cameraActor);
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true; 
		PlayerController->bEnableMouseOverEvents = true;
	}
}

void AStaticCameraController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
