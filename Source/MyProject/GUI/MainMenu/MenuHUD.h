

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuCameraActor.h" 
#include "Base/BaseMenuWidget.h"
#include "MenuHUD.generated.h"

/**
 * 
 */

// Форвардне оголошення класів віджетів
class UBaseMenuWidget;

UCLASS()
class MYPROJECT_API AMenuHUD : public AHUD
{
    GENERATED_BODY()

public:
    // Встановлення видимого віджета
    void ShowMenuWidget();
    void ShowSettingsWidget();
    void ShowCreditsWidget();

protected:
    virtual void BeginPlay() override;

    // Класи віджетів
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UBaseMenuWidget> MenuWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UBaseMenuWidget> SettingsWidgetClass;

    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UBaseMenuWidget> CreditsWidgetClass;

    // Поточний активний віджет
    UPROPERTY()
    UBaseMenuWidget* CurrentWidget;

    // Функція для перемикання між віджетами
    void SwitchWidget(TSubclassOf<UBaseMenuWidget> WidgetClass);
};