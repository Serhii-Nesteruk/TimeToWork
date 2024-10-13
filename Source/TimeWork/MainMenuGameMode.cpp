// Time to work.All Reverens Rihts.


#include "MainMenuGameMode.h"
#include "MainMenuHUD.h"

AMainMenuGameMode::AMainMenuGameMode()
{
    // Встановлюємо HUD для головного меню
    HUDClass = AMainMenuHUD::StaticClass();
}
