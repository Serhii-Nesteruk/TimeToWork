// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MenuHUD.h"

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &USettingsWidget::OnBackButtonClicked);
	}
}

void USettingsWidget::OnBackButtonClicked()
{
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD()))
	{
		MenuHUD->SwitchToCamera(MenuHUD->MainMenuCamera);
	}
}