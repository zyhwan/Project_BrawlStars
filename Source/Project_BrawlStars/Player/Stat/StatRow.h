#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StatRow.generated.h"

USTRUCT(BlueprintType)
struct FBSStatRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxHP = 2800.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed = 720.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AttackDamage = 392.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AttackRange = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AttackCooldown = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxAmmo = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AmmoReloadTime = 1.5f;
};