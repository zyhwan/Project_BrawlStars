// Fill out your copyright notice in the Description page of Project Settings.


#include "BSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


ABSPlayerController::ABSPlayerController()
{
}

void ABSPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

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
