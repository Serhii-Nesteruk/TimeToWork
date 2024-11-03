// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSprite.h"

ABaseSprite::ABaseSprite()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpriteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpriteMesh"));
	RootComponent = SpriteMesh;
	
	SpriteMesh->OnClicked.AddDynamic(this, &ABaseSprite::OnClicked);
}

void ABaseSprite::SetOnClickAction(TFunction<void()> NewOnClickAction)
{
	OnClickAction = NewOnClickAction;
}

void ABaseSprite::OnClicked(UPrimitiveComponent* ClickedComp, FKey Key)
{
	if (OnClickAction)
	{
		OnClickAction();
	}
}

void ABaseSprite::NotifyClicked(UPrimitiveComponent* ClickedComp, FKey Key)
{
	OnClicked(ClickedComp, Key); 
}