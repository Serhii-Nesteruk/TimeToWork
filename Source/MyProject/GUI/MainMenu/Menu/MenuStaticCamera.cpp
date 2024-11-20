


#include "MenuStaticCamera.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"

AMenuStaticCamera::AMenuStaticCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMenuStaticCamera::BeginPlay()
{
	Super::BeginPlay();

	// Налаштування розширення екрану
	if (UGameUserSettings* UserSettings = GEngine->GetGameUserSettings())
	{
		UserSettings->SetScreenResolution(FIntPoint(1920, 1080));
		UserSettings->ApplySettings(false);
	}

	// Встановлюємо цю камеру як основну
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(this);
}

