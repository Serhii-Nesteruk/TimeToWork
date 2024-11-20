// Fill out your copyright notice in the Description page of Project Settings.


#include "CreditWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MenuHUD.h"

void UCreditWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &UCreditWidget::OnBackButtonClicked);
	}
}

void UCreditWidget::OnBackButtonClicked()
{
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD()))
	{
		MenuHUD->SwitchToCamera(MenuHUD->MainMenuCamera);
	}
}