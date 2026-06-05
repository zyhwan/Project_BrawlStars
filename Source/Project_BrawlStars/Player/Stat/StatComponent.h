// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatRow.h"
#include "StatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_BRAWLSTARS_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// 데이터 테이블 참조
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	TObjectPtr<UDataTable> StatDataTable;

	// 어떤 캐릭터 행을 읽을지
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	FName CharacterID = TEXT("Shelly");

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	float MaxHP;

	UPROPERTY(VisibleAnywhere, Category = "Stat")
	float CurrentHP;

	// 이동
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	float Speed;

	// 공격
	UPROPERTY(EditDefaultsOnly, Category = "Stat|Attack")
	float AttackDamage;   // 투사체가 이 값 읽어감

	UPROPERTY(EditDefaultsOnly, Category = "Stat|Attack")
	float AttackRange;

	UPROPERTY(EditDefaultsOnly, Category = "Stat|Attack")
	float AttackCooldown;  // 공격 쿨타임

	UPROPERTY(EditDefaultsOnly, Category = "Stat|Attack")
	int32 MaxAmmo;

	UPROPERTY(VisibleAnywhere, Category = "Stat|Attack")
	int32 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly, Category = "Stat|Attack")
	float AmmoReloadTime;  // 탄약 1개 충전 시간
public:
	const float GetSpeed() const;

	const int32 GetMaxAmmo() const;
	const int32 GetCurrentAmmo() const;
	const float GetAttackDamage() const;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
