// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"

// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();
    if (!StatDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("StatDataTable is NULL"));
        return;
    }
    if (StatDataTable)
    {
        FBSStatRow* Row = StatDataTable->FindRow<FBSStatRow>(CharacterID, TEXT("StatComponent"));
        if (!Row)
        {
            return;
        }

        if (Row)
        {
            MaxHP = Row->MaxHP;
            Speed = Row->Speed;
            AttackDamage = Row->AttackDamage;
            AttackRange = Row->AttackRange;
            AttackCooldown = Row->AttackCooldown;
            MaxAmmo = Row->MaxAmmo;
            AmmoReloadTime = Row->AmmoReloadTime;

            // 현재값 초기화
            CurrentHP = MaxHP;
            CurrentAmmo = MaxAmmo;
        }
    }
}


// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

const float UStatComponent::GetSpeed() const
{
	return Speed;
}

const int32 UStatComponent::GetMaxAmmo() const
{
    return MaxAmmo;
}

const int32 UStatComponent::GetCurrentAmmo() const
{
    return CurrentAmmo;
}

const float UStatComponent::GetAttackDamage() const
{
    return AttackDamage;
}
