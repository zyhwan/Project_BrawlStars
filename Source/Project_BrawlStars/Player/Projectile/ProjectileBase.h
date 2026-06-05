// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;


UCLASS()
class PROJECT_BRAWLSTARS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 충돌 처리
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse,
		const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetLifeSpan(float InLifespan) override;

public:	
	// 루트 콜리전
	UPROPERTY(VisibleAnywhere, Category = "Component")
	TObjectPtr<USphereComponent> CollisionComponent;

	// 비주얼
	UPROPERTY(VisibleAnywhere, Category = "Component")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	// 이동 처리
	UPROPERTY(VisibleAnywhere, Category = "Component")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	// 데미지 (스폰 시 외부에서 주입)
	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	float Damage = 0.f;

	// 관통 여부 (쉘리는 false, 나중에 다른 캐릭터용)
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	bool bPenetrate = false;
};
