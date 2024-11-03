#include "GameController.h"

ABaseSprite* AGameController::SpawnSpriteWithAction(const FVector& Location, const FRotator& Rotation, TFunction<void()> OnClickAction)
{
	ABaseSprite* NewSprite = GetWorld()->SpawnActor<ABaseSprite>(ABaseSprite::StaticClass(), Location, Rotation);
	if (NewSprite)
	{
		NewSprite->SetOnClickAction(OnClickAction);
	}
	return NewSprite;
}

void AGameController::InitializeSprites()
{
	FillSpriteDataArray();
	SpawnSprites();
}

void AGameController::FillSpriteDataArray()
{
	SpriteDataArray.Add(FSpriteData(FVector(100, 100, 0), FRotator(0, 0, 0), [this]()
	{
		UE_LOG(LogTemp, Log, TEXT("Window 1	"));
	}));

	SpriteDataArray.Add(FSpriteData(FVector(200, 100, 0), FRotator(0, 0, 0), [this]()
	{
		UE_LOG(LogTemp, Log, TEXT("Window 2"));
	}));

	SpriteDataArray.Add(FSpriteData(FVector(300, 100, 0), FRotator(0, 0, 0), [this]()
	{
		UE_LOG(LogTemp, Log, TEXT("Window 3"));
	}));
}

void AGameController::SpawnSprites()
{
	for (const FSpriteData& Data : SpriteDataArray)
	{
		SpawnSpriteWithAction(Data.Location, Data.Rotation, Data.OnClickAction);
	}
}
