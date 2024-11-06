#include "GameController.h"

#include "../Actors/MainCameraActor.h"
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
		ABaseSprite* Sprite = Cast<ABaseSprite>(Actor);
		if (Sprite)
		{
			Sprite->SetOnClickAction(FOnSpriteClicked::CreateLambda([]() {
				UE_LOG(LogTemp, Warning, TEXT("Custom action for Blueprint Sprite!"));
			}));
		}
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
