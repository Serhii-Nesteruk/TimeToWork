// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
	protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="MainMenu")
	TSubclassOf<UUserWidget> MenuWidgetClass;
	virtual void BeginPlay() override;
};
