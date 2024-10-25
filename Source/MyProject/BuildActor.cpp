// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildActor.h"

// Sets default values
ABuildActor::ABuildActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	RootComponent = SpriteComponent;

	static ConstructorHelpers::FObjectFinder<UPaperSprite> Shop1SpriteAsset(TEXT("/Game/builds/shop1_Sprite"));

	ConfigureSprite(Shop1SpriteAsset);
}

void ABuildActor::BeginPlay()
{
	Super::BeginPlay();
	SpriteComponent->OnClicked.AddDynamic(this, &ABuildActor::OnSpriteClicked);
}

void ABuildActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuildActor::OnSpriteClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed == EKeys::LeftMouseButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sprite clicked!"));
	}
}

void ABuildActor::ConfigureSprite(PaperSpriteFinder& sprite)
{
	if (sprite.Succeeded())
	{
		UPaperSprite* PaperSprite = Cast<UPaperSprite>(sprite.Object);
		if (PaperSprite)
		{
			SpriteComponent->SetSprite(sprite.Object);  
			SpriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			SpriteComponent->SetCollisionObjectType(ECC_WorldDynamic);
			SpriteComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
			SpriteComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
		}
	}
}

