#include "GameController.h"

#include "../Actors/MainCameraActor.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AGameController::AGameController()
{
	
}

void AGameController::BeginPlay()
{
	Super::BeginPlay();
	SetupCamera();
	SettingUpHouses();
}

void AGameController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void AGameController::SettingUpHouses()
{
	TArray<AActor*> FoundSprites;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseSprite::StaticClass(), FoundSprites);

	for (AActor* Actor : FoundSprites)
	{
		AHouseSprite* Sprite = Cast<AHouseSprite>(Actor);
		if (Sprite->GetModalWindowClass() != nullptr)
		{
			Sprite->SetOnClickAction(FOnSpriteClicked::CreateWeakLambda(this, [this, Sprite]() {
				OpenModalWindow(Sprite->GetModalWindowClass());
			}));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Sprite %s has no modal window class assigned."), *Sprite->GetName());
		}
	}
}

void AGameController::OpenModalWindow(const TSubclassOf<UUserWidget>& ModalClass)
{
	if (ModalClass)
	{
		UUserWidget* ModalWidget = CreateWidget<UUserWidget>(this, ModalClass);
		if (ModalWidget)
		{
			ModalWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("Modal window opened: %s"), *ModalClass->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create modal widget: %s"), *ModalClass->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No modal class specified for this sprite."));
	}
}

void AGameController::SetupCamera()
{
	ACameraActor* cameraActor =
	Cast<ACameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AMainCameraActor::StaticClass()));
	if (cameraActor)
	{
		SetViewTarget(cameraActor);
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true; 
		PlayerController->bEnableMouseOverEvents = true;
	}
}
