

#include "MenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MenuHUD.h"


void UMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnPlayButtonClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnSettingsButtonClicked);
	}
	if (CreditButton)
	{
		CreditButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnSettingsButtonClicked);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnQuitButtonClicked);
	}
}

void UMenuUserWidget::OnPlayButtonClicked()
{
	// Завантажуємо основний рівень гри
	const FName StartupLevelName = "MainMap";
	UGameplayStatics::OpenLevel(this,StartupLevelName);
}

void UMenuUserWidget::OnSettingsButtonClicked()
{
	// Реалізуйте відкриття налаштувань (можна переключити камеру або відкрити новий віджет)
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD()))
	{
		// Наприклад, переключення на камеру налаштувань (якщо вона існує)
		MenuHUD->SwitchToCamera(MenuHUD->SettingsCamera); // Замініть SettingsCamera
	}
}

void UMenuUserWidget::OnCreditButtonClicked()
{
	// Переключення на камеру кредитів
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD()))
	{
		MenuHUD->SwitchToCamera(MenuHUD->CreditCamera);
	}
}

void UMenuUserWidget::OnQuitButtonClicked()
{
	// Вихід із гри
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}