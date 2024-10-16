// Time to work.All Reverens Rihts.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenuWidget::Initialize()
{
    Super::Initialize();

    if (PlayButton)
    {
        PlayButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPlayClicked);
    }

    if (SettingsButton)
    {
        SettingsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSettingsClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
    }

    return true;
}

void UMainMenuWidget::OnPlayClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Play Button Clicked!"));
    // ������� ����� ������� ��� ���
}

void UMainMenuWidget::OnSettingsClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Settings Button Clicked!"));
    // ������� ����� ��� �������� ���� �����������
}

void UMainMenuWidget::OnQuitClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("Quit Button Clicked!"));
    // ����� ������ � ���
    UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
