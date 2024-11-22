// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseMenuWidget.h"
#include "SettingsWidget.generated.h"

/**
 * Клас для меню налаштувань
 */
UCLASS()
class MYPROJECT_API USettingsWidget : public UBaseMenuWidget
{
	GENERATED_BODY()
public:
	// Властивості для налаштувань
	UPROPERTY(meta = (BindWidget))
	class USlider* VolumeSlider;

	UPROPERTY(meta = (BindWidget))
	class UCheckBox* FullscreenCheckbox;

protected:
	virtual void NativeConstruct() override;

	// Обробники подій
	UFUNCTION()
	void OnVolumeSliderChanged(float Value);

	UFUNCTION()
	void OnFullscreenCheckboxChanged(bool bIsChecked);
};
