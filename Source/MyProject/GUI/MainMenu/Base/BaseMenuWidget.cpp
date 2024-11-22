// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MenuHUD.h"

void UBaseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Прив'язуємо кнопку "Назад" до обробника
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &UBaseMenuWidget::OnBackButtonClicked);
	}
}

void UBaseMenuWidget::OnBackButtonClicked()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (PlayerController)
	{
		AMenuHUD* MenuHUD = Cast<AMenuHUD>(PlayerController->GetHUD());
		if (MenuHUD)
		{
			MenuHUD->ShowMenuWidget(); // Повернення до головного меню
		}
	}
}

void UBaseMenuWidget::CloseMenu()
{
	RemoveFromParent();
}