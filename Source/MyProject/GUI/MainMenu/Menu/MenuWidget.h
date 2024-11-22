// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base//BaseMenuWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnPlayButtonClicked();

	UFUNCTION()
	void OnSettingsButtonClicked();

	UFUNCTION()
	void OnCreditsButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

	// Прив'язки кнопок
	UPROPERTY(meta = (BindWidget))
	class UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CreditsButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;
};
