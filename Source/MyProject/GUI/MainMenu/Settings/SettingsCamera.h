

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "SettingsCamera.generated.h"

UCLASS()
class MYPROJECT_API ASettingsCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	// Конструктор
	ASettingsCamera();

protected:
	// Логіка при запуску
	virtual void BeginPlay() override;

public:
	// Виконується щокадрово
	virtual void Tick(float DeltaTime) override;
};
