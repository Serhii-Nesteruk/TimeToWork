
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraActor.h"
#include "MenuStaticCamera.generated.h"

UCLASS()
class MYPROJECT_API AMenuStaticCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:	
	// Конструктор
	AMenuStaticCamera();

protected:
	virtual void BeginPlay() override;
};

