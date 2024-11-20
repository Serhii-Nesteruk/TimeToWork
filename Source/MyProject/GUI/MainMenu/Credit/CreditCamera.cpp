


#include "CreditCamera.h"

// Конструктор
ACreditCamera::ACreditCamera()
{
	// Увімкнути тік, якщо потрібна логіка щокадрово
	PrimaryActorTick.bCanEverTick = true;
}

// Логіка при запуску
void ACreditCamera::BeginPlay()
{
	Super::BeginPlay();
    
	// Додаткова логіка для камери кредитів (за необхідності)
}

// Логіка щокадрово
void ACreditCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
	// Додайте вашу специфічну логіку для камери кредитів
}

