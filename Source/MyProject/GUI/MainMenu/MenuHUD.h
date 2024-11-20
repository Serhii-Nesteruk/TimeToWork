

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	// Камери
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
	AActor* MainMenuCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
	AActor* CreditCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cameras")
	AActor* SettingsCamera;

	// Функції для керування камерами та віджетами
	UFUNCTION(BlueprintCallable, Category = "Cameras")
	void SwitchToCamera(AActor* NewCamera);

	void ShowSettingsWidget();
	void ShowCreditWidget();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> SettingsWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> CreditWidgetClass;

private:
	UPROPERTY()
	UUserWidget* CurrentSettingsWidget;
	UPROPERTY()
	UUserWidget* CurrentCreditWidget;

protected:
	// Клас віджета головного меню
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MainMenu")
	TSubclassOf<UUserWidget> MenuWidgetClass;

	// Поточний активний віджет
	UPROPERTY()
	UUserWidget* CurrentWidget;

	// Ініціалізація при запуску
	virtual void BeginPlay() override;
};
