


#include "MenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	// Створення та додавання віджета головного меню
	if (MenuWidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}

	// Ініціалізація камер через прив'язки
	if (!MainMenuCamera)
	{
		MainMenuCamera = UGameplayStatics::GetActorOfClass(GetWorld(), AActor::StaticClass());
	}
	if (!CreditCamera)
	{
		CreditCamera = UGameplayStatics::GetActorOfClass(GetWorld(), AActor::StaticClass());
	}
	if (!SettingsCamera)
	{
		SettingsCamera = UGameplayStatics::GetActorOfClass(GetWorld(), AActor::StaticClass());
	}
}

void AMenuHUD::SwitchToCamera(AActor* NewCamera)
{
	if (APlayerController* PlayerController = GetOwningPlayerController())
	{
		if (NewCamera)
		{
			PlayerController->SetViewTarget(NewCamera);
		}
	}
}
void AMenuHUD::ShowSettingsWidget()
{
	// Переконатися, що попередній віджет видалений
	if (CurrentCreditWidget && CurrentCreditWidget->IsInViewport())
	{
		CurrentCreditWidget->RemoveFromParent();
	}

	if (SettingsWidgetClass)
	{
		if (!CurrentSettingsWidget)
		{
			CurrentSettingsWidget = CreateWidget<UUserWidget>(GetWorld(), SettingsWidgetClass);
		}

		if (CurrentSettingsWidget && !CurrentSettingsWidget->IsInViewport())
		{
			CurrentSettingsWidget->AddToViewport();
		}
	}
}

void AMenuHUD::ShowCreditWidget()
{
	// Переконатися, що попередній віджет видалений
	if (CurrentSettingsWidget && CurrentSettingsWidget->IsInViewport())
	{
		CurrentSettingsWidget->RemoveFromParent();
	}

	if (CreditWidgetClass)
	{
		if (!CurrentCreditWidget)
		{
			CurrentCreditWidget = CreateWidget<UUserWidget>(GetWorld(), CreditWidgetClass);
		}

		if (CurrentCreditWidget && !CurrentCreditWidget->IsInViewport())
		{
			CurrentCreditWidget->AddToViewport();
		}
	}
}