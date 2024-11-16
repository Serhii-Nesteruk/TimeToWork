// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseSprite.h"
#include "HouseSprite.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHouseSprite : public ABaseSprite
{
	GENERATED_BODY()
public:
	AHouseSprite();

	TSubclassOf<UUserWidget> GetModalWindowClass() const { return ModalWindowClass; }
	void SetModalWindowClass(TSubclassOf<UUserWidget> NewClass) { ModalWindowClass = NewClass; }

private:
	UPROPERTY(EditAnywhere, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> ModalWindowClass;
};