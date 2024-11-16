
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "MenuStaticCamera.generated.h"

UCLASS()
class MYPROJECT_API AMenuStaticCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Конструктор
	AMenuStaticCamera();

protected:
	// Компонент камери
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	UCameraComponent* CameraComponent;
	
	virtual void BeginPlay() override;
};

