// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	// Функція для закриття цього віджета
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseMenu();

protected:
	// Прив'язка кнопки "Назад"
	UPROPERTY(meta = (BindWidgetOptional))
	class UButton* BackButton;

	virtual void NativeConstruct() override;

	// Обробник для кнопки "Назад"
	UFUNCTION()
	virtual void OnBackButtonClicked();
};