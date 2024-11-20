


#include "SettingsCamera.h"


/// Конструктор
ASettingsCamera::ASettingsCamera()
{
	// Увімкнути тік, якщо потрібна логіка щокадрово
	PrimaryActorTick.bCanEverTick = true;
}

// Логіка при запуску
void ASettingsCamera::BeginPlay()
{
	Super::BeginPlay();
    
	// Додаткова логіка для камери налаштувань (за необхідності)
}

// Логіка щокадрово
void ASettingsCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
	// Додайте вашу специфічну логіку для камери налаштувань
}

