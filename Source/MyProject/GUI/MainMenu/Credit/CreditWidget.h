// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/BaseMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "CreditWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UCreditWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

public:
	// Можливість додавання додаткових функцій або властивостей

protected:
	virtual void NativeConstruct() override;

	// Якщо необхідно, можна додати додаткові обробники подій тут
};