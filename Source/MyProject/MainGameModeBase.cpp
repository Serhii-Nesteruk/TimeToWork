// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"

#include "StaticCameraController.h"

AMainGameModeBase::AMainGameModeBase()
{
	PlayerControllerClass = AStaticCameraController::StaticClass();
}
