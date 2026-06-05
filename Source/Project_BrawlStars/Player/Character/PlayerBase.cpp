// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Project_BrawlStars/Player/Stat/StatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 스탯 컴포넌트 생성
	StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));

	//SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = 1600.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;
	SpringArm->SetWorldRotation(FRotator(-50.f, 0.f, 0.f)); // Absolute Rotation
	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 55.f;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (StatComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), StatComponent->GetSpeed());
		GetCharacterMovement()->MaxWalkSpeed = StatComponent->GetSpeed();
	}
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (UIC)
	{
		UIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerBase::Move);
		UIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &APlayerBase::Fire);
		UIC->BindAction(IA_Aim, ETriggerEvent::Triggered, this, &APlayerBase::Aim);
	}


}

void APlayerBase::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	// 카메라 기준이 아닌 월드 기준 고정 방향으로 변경
	// 쿼터뷰는 카메라가 고정이라 월드 기준이 더 자연스러움
	AddMovementInput(FVector::ForwardVector, Direction.X);
	AddMovementInput(FVector::RightVector, Direction.Y);
}

void APlayerBase::Fire(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Fire!!"));
}

void APlayerBase::Aim(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Aim!!"));
}

