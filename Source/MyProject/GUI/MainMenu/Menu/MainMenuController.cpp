
#include "MainMenuController.h"
#include "MenuUserWidget.h"
#include "Blueprint/UserWidget.h"

void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
	if (UMenuUserWidget* MenuUserWidget = CreateWidget<UMenuUserWidget>(this, UMenuUserWidget::StaticClass()))
	{
		MenuUserWidget->AddToViewport();
		SetShowMouseCursor(true);
	} 
	
}