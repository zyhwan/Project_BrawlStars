// Fill out your copyright notice in the Description page of Project Settings.


#include "Shelly.h"
#include "Project_BrawlStars/Player/Projectile/ProjectileBase.h"
#include "Project_BrawlStars/Player/Stat/StatComponent.h"

AShelly::AShelly()
{
}

void AShelly::Fire(const FInputActionValue& Value)
{
	Super::Fire(Value);

    if (!StatComponent) return;

    // 탄약 체크
    if (StatComponent->GetCurrentAmmo() <= 0) return;

    // 캐릭터 앞쪽 발사 위치
    FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.f;
    FRotator BaseRotation = GetActorRotation();

    // 부채꼴로 N발 발사
    float HalfSpread = SpreadAngle * 0.5f;
    float AngleStep = (BulletCount > 1) ? SpreadAngle / (BulletCount - 1) : 0.f;

    for (int32 i = 0; i < BulletCount; i++)
    {
        float CurrentAngle = -HalfSpread + AngleStep * i;
        FRotator BulletRotation = BaseRotation;
        BulletRotation.Yaw += CurrentAngle;

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = this;
        SpawnParams.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        AProjectileBase* Bullet = GetWorld()->SpawnActor<AProjectileBase>(
            BulletClass, SpawnLocation, BulletRotation, SpawnParams);

        if (Bullet)
        {
            // StatComponent에서 데미지 값 주입
            Bullet->Damage = StatComponent->GetAttackDamage();
            UE_LOG(LogTemp, Warning, TEXT("Attack Damage : %f"), StatComponent->GetAttackDamage());
        }
    }

}

void AShelly::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AShelly::BeginPlay()
{
    Super::BeginPlay();

}
