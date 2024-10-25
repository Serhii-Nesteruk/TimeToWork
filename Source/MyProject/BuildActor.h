// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"  
#include "BuildActor.generated.h"

UCLASS()
class MYPROJECT_API ABuildActor : public AActor
{
	GENERATED_BODY()

private:
	using PaperSpriteFinder = ConstructorHelpers::FObjectFinder<UPaperSprite>;
	
public:	
	ABuildActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Components");
	UPaperSpriteComponent* SpriteComponent = nullptr;

	UFUNCTION()
	void OnSpriteClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

private:
	void SpriteSetups();
	void ConfigureSprite(PaperSpriteFinder& sprite);
};
