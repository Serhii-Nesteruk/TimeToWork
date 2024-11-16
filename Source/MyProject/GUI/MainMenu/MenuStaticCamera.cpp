


#include "MenuStaticCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"


AMenuStaticCamera::AMenuStaticCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Створюємо компонент камери та прикріплюємо його до кореневого компонента
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;

	// Налаштовуємо статичну позицію та ротацію камери
	CameraComponent->SetWorldLocation(FVector(0.0f, 0.0f, 760.0f)); // Задайте висоту та положення
	CameraComponent->SetWorldRotation(FRotator(-0.0f, 0.0f, 0.0f)); // Направлення вниз
	// Налаштування співвідношення сторін для камери на 16:9
	CameraComponent->SetAspectRatio(16.0f / 9.0f);
	CameraComponent->SetFieldOfView(100.0f); // Налаштуйте поле огляду на свій розсуд
	CameraComponent->SetConstraintAspectRatio(true);
}

// Called when the game starts or when spawned
void AMenuStaticCamera::BeginPlay()
{
	Super::BeginPlay();
	
	// Отримуємо налаштування користувача і встановлюємо розширення
	if (UGameUserSettings* UserSettings = GEngine->GetGameUserSettings())
	{
		UserSettings->SetScreenResolution(FIntPoint(1920, 1080));
		UserSettings->ApplySettings(false);
	}
	// Встановлюємо цю камеру як основну
	if (CameraComponent)
	{
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(this);
	}
}

