#pragma once

#include <CoreMinimal.h>
#include "Base/BaseMenuWidget.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuController.generated.h"


// Форвардне оголошення класу
class UBaseMenuWidget;

UCLASS()
class MYPROJECT_API AMainMenuController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Клас віджету для основного меню
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UBaseMenuWidget> MenuWidgetClass;

	// Вказівник на створений віджет
	UPROPERTY()
	UBaseMenuWidget* MenuWidget;

	virtual void BeginPlay() override;
};