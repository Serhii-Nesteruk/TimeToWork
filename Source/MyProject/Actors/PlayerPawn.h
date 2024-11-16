// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyProject/Sprites/PlayerSprite.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MYPROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetPlayerSprite(APlayerSprite* NewPlayerSprite) { PlayerSprite = NewPlayerSprite; }

	[[nodiscard]] APlayerSprite* GetPlayerSprite() const { return PlayerSprite; }
private:
	UPROPERTY(VisibleAnywhere, Category = "Sprite")
	APlayerSprite* PlayerSprite;
};
