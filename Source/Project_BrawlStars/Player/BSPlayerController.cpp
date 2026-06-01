// Fill out your copyright notice in the Description page of Project Settings.


#include "BSPlayerController.h"
#include "Character/PlayerBase.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Kismet/KismetMathLibrary.h"

void ABSPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    UpdateCharacterRotation();
}

void ABSPlayerController::UpdateCharacterRotation()
{
    // 빙의된 캐릭터 가져오기
    APlayerBase* MyCharacter = Cast<APlayerBase>(GetPawn());
    if (!MyCharacter) return;

    // 커서가 가리키는 월드 좌표
    FHitResult HitResult;
    GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

    if (HitResult.bBlockingHit)
    {
        FVector TargetLocation = HitResult.Location;
        FVector MyLocation = MyCharacter->GetActorLocation();
        TargetLocation.Z = MyLocation.Z;

        FVector Direction = (TargetLocation - MyLocation).GetSafeNormal();
        FRotator NewRotation = FRotator(0.f, UKismetMathLibrary::MakeRotFromX(Direction).Yaw, 0.f);

        // 컨트롤러 회전값 설정
        SetControlRotation(NewRotation);
    }
}

void ABSPlayerController::BeginPlay()
{
    SetShowMouseCursor(true);
    if (IsLocalPlayerController())
    {

        UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

        if (Subsystem)
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(IMC_Input, 0);
        }
    }
}

ABSPlayerController::ABSPlayerController()
{
}

void ABSPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);
}

void ABSPlayerController::OnUnPossess()
{
    Super::OnUnPossess();

    if (IsLocalPlayerController())
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

        if (Subsystem)
        {
            Subsystem->ClearAllMappings();
        }
    }
}
