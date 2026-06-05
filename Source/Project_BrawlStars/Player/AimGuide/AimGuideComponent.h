// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AimGuideComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_BRAWLSTARS_API UAimGuideComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimGuideComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 자식 클래스에서 구현
	virtual void ShowGuide();
	virtual void HideGuide();
	virtual void UpdateGuide(const FVector& Direction);
protected:
	UPROPERTY(VisibleAnywhere)
	bool bIsVisible = false;

	// 가이드 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AimGuide")
	float GuideRange = 500.f;
};
