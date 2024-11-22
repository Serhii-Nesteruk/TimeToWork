// Fill out your copyright notice in the Description page of Project Settings.


#include "CreditWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Base/BaseMenuWidget.h"
#include "MenuHUD.h"

void UCreditWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Якщо у вас є додаткові кнопки або елементи, прив'яжіть їх тут
	// Прив'язка кнопки "Назад" вже здійснюється в UBaseMenuWidget
}