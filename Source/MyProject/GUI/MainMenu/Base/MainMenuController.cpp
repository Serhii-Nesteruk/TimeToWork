
#include "MainMenuController.h"

#include "EngineUtils.h"
#include "MenuCameraActor.h"
#include "Menu/MenuWidget.h"
#include "Base/BaseMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


void AMainMenuController::BeginPlay()
{
	Super::BeginPlay();

	// Встановлюємо режим вводу та показуємо курсор миші
	FInputModeUIOnly InputMode;
	SetInputMode(InputMode);
	bShowMouseCursor = true;

	// Знаходимо основну камеру
	FString TargetCameraName = TEXT("BP_MenuCameraActor");
	for (TActorIterator<AMenuCameraActor> It(GetWorld()); It; ++It)
	{
		if (It->GetFName().ToString() == TargetCameraName)
		{
			SetViewTarget(*It);
			break;
		}
	}

	// Створення та показ основного меню
	if (MenuWidgetClass)
	{
		MenuWidget = CreateWidget<UBaseMenuWidget>(this, MenuWidgetClass);
		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
			InputMode.SetWidgetToFocus(MenuWidget->TakeWidget());
			SetInputMode(InputMode);
		}
	}
}
