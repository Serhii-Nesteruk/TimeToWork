
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraActor.h"
#include "MenuCameraActor.generated.h"

UCLASS()
class MYPROJECT_API AMenuCameraActor : public ACameraActor
{
	GENERATED_BODY()
	
public:	
	/** Конструктор для ініціалізації базових значень */
	AMenuCameraActor();

protected:
	/** Ініціалізація при запуску */
	virtual void BeginPlay() override;

private:
	/** Розширення екрану (налаштовується через редактор) */
	UPROPERTY(EditAnywhere, Category = "Settings")
	FIntPoint ScreenResolution = FIntPoint(1920, 1080);

	/** Чи застосовувати розширення екрана */
	UPROPERTY(EditAnywhere, Category = "Settings")
	bool bApplyScreenResolution = true;
};

