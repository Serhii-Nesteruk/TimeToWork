﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreditWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UCreditWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnBackButtonClicked();
};
