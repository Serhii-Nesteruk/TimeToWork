// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseSprite.h"
#include "GameController.generated.h"

UCLASS()
class MYPROJECT_API AGameController : public APlayerController
{
	GENERATED_BODY()
public:
	ABaseSprite* SpawnSpriteWithAction(const FVector& Location, const FRotator& Rotation, TFunction<void()> OnClickAction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprites")
	TArray<FSpriteData> SpriteDataArray;
	
	void InitializeSprites();

private:
	void FillSpriteDataArray();
	void SpawnSprites();
};
