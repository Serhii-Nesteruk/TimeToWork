#include "BaseSprite.h"

ABaseSprite::ABaseSprite()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpriteMesh = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteMesh"));
	RootComponent = SpriteMesh;
	
	SpriteMesh->OnClicked.AddDynamic(this, &ABaseSprite::OnClicked);
}

void ABaseSprite::SetOnClickAction(FOnSpriteClicked NewOnClickAction)
{
	OnSpriteClickedAction = NewOnClickAction;
}

void ABaseSprite::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseSprite::OnClicked(UPrimitiveComponent* ClickedComp, FKey Key)
{
	if (OnSpriteClickedAction.IsBound())
	{
		OnSpriteClickedAction.Execute();
	}
}

void ABaseSprite::NotifyClicked(UPrimitiveComponent* ClickedComp, FKey Key)
{
	OnClicked(ClickedComp, Key); 
}
