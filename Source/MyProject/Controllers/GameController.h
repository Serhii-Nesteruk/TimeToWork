// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "../Sprites/BaseSprite.h"
#include "GameController.generated.h"

UCLASS()
class MYPROJECT_API AGameController : public APlayerController
{
	GENERATED_BODY()	
public:

	AGameController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	void SettingUpHouses();

private:
	void SetupCamera();
};
