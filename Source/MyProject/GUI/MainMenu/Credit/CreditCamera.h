

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CreditCamera.generated.h"

/**
 * Камера для екрану кредитів
 */
UCLASS()
class MYPROJECT_API ACreditCamera : public ACameraActor
{
	GENERATED_BODY()

public:
	// Конструктор
	ACreditCamera();

protected:
	// Логіка при запуску
	virtual void BeginPlay() override;

public:
	// Виконується щокадрово
	virtual void Tick(float DeltaTime) override;
};
