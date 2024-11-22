// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "MenuHUD.h"
#include "Base/BaseMenuWidget.h" 
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UMenuWidget::OnPlayButtonClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UMenuWidget::OnSettingsButtonClicked);
	}

	if (CreditsButton)
	{
		CreditsButton->OnClicked.AddDynamic(this, &UMenuWidget::OnCreditsButtonClicked);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitButtonClicked);
	}
}

void UMenuWidget::OnPlayButtonClicked()
{
	UGameplayStatics::OpenLevel(this, FName("MainLevel")); // Завантаження рівня
}

void UMenuWidget::OnSettingsButtonClicked()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (PlayerController)
	{
		AMenuHUD* MenuHUD = Cast<AMenuHUD>(PlayerController->GetHUD());
		if (MenuHUD)
		{
			MenuHUD->ShowSettingsWidget();
		}
	}
}

void UMenuWidget::OnCreditsButtonClicked()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (PlayerController)
	{
		AMenuHUD* MenuHUD = Cast<AMenuHUD>(PlayerController->GetHUD());
		if (MenuHUD)
		{
			MenuHUD->ShowCreditsWidget();
		}
	}
}

void UMenuWidget::OnQuitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}