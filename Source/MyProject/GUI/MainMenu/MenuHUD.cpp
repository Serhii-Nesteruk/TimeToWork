


#include "MenuHUD.h"
#include "EngineUtils.h"
#include "Base/BaseMenuWidget.h"
#include "Settings/SettingsWidget.h"
#include "Credit/CreditWidget.h"
#include "Blueprint/UserWidget.h"
#include "MenuCameraActor.h" 
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AMenuHUD::BeginPlay()
{
    Super::BeginPlay();
    

    // Показуємо основне меню під час запуску
    ShowMenuWidget();
}



void AMenuHUD::SwitchWidget(TSubclassOf<UBaseMenuWidget> WidgetClass)
{
    // Закриваємо поточний віджет, якщо він є
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromParent();
        CurrentWidget = nullptr;
    }

    // Створюємо новий віджет
    if (WidgetClass)
    {
        CurrentWidget = CreateWidget<UBaseMenuWidget>(GetWorld(), WidgetClass);
        if (CurrentWidget)
        {
            CurrentWidget->AddToViewport();

            // Налаштовуємо фокус вводу
            APlayerController* PlayerController = GetOwningPlayerController();
            if (PlayerController)
            {
                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget());
                PlayerController->SetInputMode(InputMode);
                PlayerController->bShowMouseCursor = true;
            }
        }
    }
}

void AMenuHUD::ShowMenuWidget()
{
    SwitchWidget(MenuWidgetClass);
}

void AMenuHUD::ShowSettingsWidget()
{
    SwitchWidget(SettingsWidgetClass);
}

void AMenuHUD::ShowCreditsWidget()
{
    SwitchWidget(CreditsWidgetClass);
}