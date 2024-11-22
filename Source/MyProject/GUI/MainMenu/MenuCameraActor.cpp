


#include "MenuCameraActor.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"

AMenuCameraActor::AMenuCameraActor()
{
	PrimaryActorTick.bCanEverTick = false; // Камера є статичною
}

void AMenuCameraActor::BeginPlay()
{
	Super::BeginPlay();

	// Налаштування розширення екрану (якщо дозволено)
	if (bApplyScreenResolution)
	{
		if (UGameUserSettings* UserSettings = GEngine->GetGameUserSettings())
		{
			UserSettings->SetScreenResolution(ScreenResolution);
			UserSettings->ApplySettings(false);
		}
	}
}

