#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "BaseSprite.generated.h"

DECLARE_DELEGATE(FOnSpriteClicked);

USTRUCT(BlueprintType)
struct FSpriteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Data")
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Data")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Data")
	UPaperSprite* Sprite;   

	FOnSpriteClicked OnSpriteClickedAction;
	
	FSpriteData() = default;

	FSpriteData(const FVector& InLocation, const FRotator& InRotation, FOnSpriteClicked OnSpriteClickedAction, UPaperSprite* InSprite)
		: Location(InLocation), Rotation(InRotation), OnSpriteClickedAction(OnSpriteClickedAction), Sprite(InSprite) {}
};

UCLASS()
class MYPROJECT_API ABaseSprite : public AActor
{
	GENERATED_BODY()

public:
	ABaseSprite();

	void SetOnClickAction(FOnSpriteClicked NewOnClickAction);
	virtual void BeginPlay() override;

	UPaperSpriteComponent* GetSpriteMesh() const { return SpriteMesh; }

protected:
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* ClickedComp, FKey Key);

public:
	void NotifyClicked(UPrimitiveComponent* ClickedComp, FKey Key);

private:
	FOnSpriteClicked OnSpriteClickedAction;

	UPROPERTY(VisibleAnywhere, Category = "Sprite")
	UPaperSpriteComponent* SpriteMesh;
};
