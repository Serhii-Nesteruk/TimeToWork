// Time to work.All Reverens Rihts.


#include "MainMenuHUD.h"
#include "Blueprint/UserWidget.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    // Створюємо головне меню
    CreateMainMenu();
}

void AMainMenuHUD::CreateMainMenu()
{
    if (GEngine && GEngine->GameViewport)
    {
        // Пошук віджета головного меню
        static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetClass(TEXT("/Game/UI/MainMenuWidget"));

        if (MainMenuWidgetClass.Class)
        {
            UUserWidget* MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass.Class);

            if (MainMenu)
            {
                MainMenu->AddToViewport();
            }
        }
    }
}
