// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSprite.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClickDelegate, UPrimitiveComponent*, ClickedComponent, FKey, Key);

USTRUCT(BlueprintType)
struct FSpriteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Data")
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite Data")
	FRotator Rotation;

	// Замість FOnClickDelegate використовуйте TFunction<void()>
	TFunction<void()> OnClickAction;

	FSpriteData() {}

	FSpriteData(const FVector& InLocation, const FRotator& InRotation, TFunction<void()> InOnClickAction)
		: Location(InLocation), Rotation(InRotation), OnClickAction(InOnClickAction) {}
};

UCLASS()
class MYPROJECT_API ABaseSprite : public AActor
{
	GENERATED_BODY()

public:
	ABaseSprite();
	
	void SetOnClickAction(TFunction<void()> NewOnClickAction);

protected:
	
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* ClickedComp, FKey Key); 
public:
	void NotifyClicked(UPrimitiveComponent* ClickedComp, FKey Key);

private:
	TFunction<void()> OnClickAction;

	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SpriteMesh;

};
