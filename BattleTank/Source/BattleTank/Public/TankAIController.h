// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank * GetControllerTank() const;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	ATank * GetPlayerTank() const;
	
private:
	//aim barrel of tank on crosshair
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
