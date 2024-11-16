// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSprite.h"
#include "PlayerSprite.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API APlayerSprite : public ABaseSprite
{
	GENERATED_BODY()
	
public:	
	APlayerSprite();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	FVector Velocity;

public:	
	virtual void Tick(float DeltaTime) override;
	
	void HandleInput(float DeltaTime);
};