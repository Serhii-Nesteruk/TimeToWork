


#include "MainMenuGameModeBase.h"
#include "MainMenuController.h"
#include "MenuHUD.h"

AMainMenuGameModeBase::AMainMenuGameModeBase()
{
	PlayerControllerClass = AMainMenuController::StaticClass();
	HUDClass = AMainMenuController::StaticClass();
	
}
