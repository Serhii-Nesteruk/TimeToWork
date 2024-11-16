// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSprite.h"

APlayerSprite::APlayerSprite()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerSprite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	HandleInput(DeltaTime);
}

void APlayerSprite::HandleInput(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	
	NewLocation.X += Velocity.X * DeltaTime;
	NewLocation.Y += Velocity.Y * DeltaTime;

	SetActorLocation(NewLocation);
}