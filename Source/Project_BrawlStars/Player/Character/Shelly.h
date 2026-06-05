// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBase.h"
#include "Shelly.generated.h"

class AProjectileBase;

/**
 * 
 */
UCLASS()
class PROJECT_BRAWLSTARS_API AShelly : public APlayerBase
{
	GENERATED_BODY()
public:
	AShelly();

	virtual void Fire(const FInputActionValue& Value) override;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	TSubclassOf<AProjectileBase> BulletClass;

	// 부채꼴 발사 각도
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	float SpreadAngle = 30.f;

	// 발사 수
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	int32 BulletCount = 3;
};
