


#include "MainMenuGameModeBase.h"
#include "MainMenuController.h"
#include "MenuHUD.h"

AMainMenuGameModeBase::AMainMenuGameModeBase()
{
	// Призначення класу контролера
	PlayerControllerClass = AMainMenuController::StaticClass();

	// Призначення класу HUD
	HUDClass = AMenuHUD::StaticClass();

	// Відсутність персонажа в головному меню
	DefaultPawnClass = nullptr;
}
