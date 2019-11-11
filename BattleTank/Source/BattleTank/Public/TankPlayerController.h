// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
private:
	//aim barrel of tank on crosshair
	void AimTowardsCrosshair();
	bool GetLookLocation(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(editanywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(editanywhere)
		float CrossHairYLocation = 0.33333;
	UPROPERTY(editanywhere) 
		float LineTraceRange = 1000000;
	FVector2D ScreenLocation;
	

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetControllerTank() const;

};
