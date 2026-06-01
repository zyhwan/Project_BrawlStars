// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerBase::UpdateRotationToMouseCursor()
{


}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateRotationToMouseCursor();

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (UIC)
	{
		UIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerBase::Move);
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

