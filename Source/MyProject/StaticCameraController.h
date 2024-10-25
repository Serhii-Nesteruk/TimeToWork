// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StaticCameraController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AStaticCameraController : public APlayerController
{
	GENERATED_BODY()
public:
	AStaticCameraController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
};
