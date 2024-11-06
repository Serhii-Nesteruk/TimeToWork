// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"


void UMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnPlayButtonClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnSettingsButtonClicked);
	}
	if (CreditButton)
	{
		CreditButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnSettingsButtonClicked);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnQuitButtonClicked);
	}
}

void UMenuUserWidget::OnPlayButtonClicked()
{
	// Завантажуємо основний рівень гри
	const FName StartupLevelName = "MainMap";
	UGameplayStatics::OpenLevel(this,StartupLevelName);
}

void UMenuUserWidget::OnSettingsButtonClicked()
{
	// Логіка для меню налаштувань (поки без дій)
}
void UMenuUserWidget::OnCreditButtonClicked()
{
	//логіка для списку творців ігрию.
}

void UMenuUserWidget::OnQuitButtonClicked()
{
	// Завершення гри
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}