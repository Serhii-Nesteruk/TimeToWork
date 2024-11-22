// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Slider.h"
#include "Components/CheckBox.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (VolumeSlider)
	{
		VolumeSlider->OnValueChanged.AddDynamic(this, &USettingsWidget::OnVolumeSliderChanged);
	}
	if (FullscreenCheckbox)
	{
		FullscreenCheckbox->OnCheckStateChanged.AddDynamic(this, &USettingsWidget::OnFullscreenCheckboxChanged);
	}
}

void USettingsWidget::OnVolumeSliderChanged(float Value)
{
	// Реалізація зміни гучності
	UE_LOG(LogTemp, Log, TEXT("Volume Slider Changed: %f"), Value);
	// Тут можна додати код для зміни гучності звуку в грі
}

void USettingsWidget::OnFullscreenCheckboxChanged(bool bIsChecked)
{
	if (UGameUserSettings* UserSettings = GEngine->GetGameUserSettings())
	{
		UserSettings->SetFullscreenMode(bIsChecked ? EWindowMode::Fullscreen : EWindowMode::Windowed);
		UserSettings->ApplySettings(false);
		UE_LOG(LogTemp, Log, TEXT("Fullscreen Checkbox Changed: %s"), bIsChecked ? TEXT("Checked") : TEXT("Unchecked"));
	}
}
