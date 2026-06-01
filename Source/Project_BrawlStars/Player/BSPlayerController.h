// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BSPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PROJECT_BRAWLSTARS_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void PlayerTick(float DeltaTime) override;

private:
	void UpdateCharacterRotation();

public:
	virtual void BeginPlay() override;
	ABSPlayerController();

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	TObjectPtr<UInputMappingContext> IMC_Input;

};
