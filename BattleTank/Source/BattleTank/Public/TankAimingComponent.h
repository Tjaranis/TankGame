// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel; 
class UTankTurret;

//hold barrel's property
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret * TurretToSet);
	FVector AimDirection(FVector HitLocation, float LaunchSpeed);
	void MoveBarrel(FVector AimDirection);
	bool BarrelAlignedWithTarget = false;
	float AccuracySpread = 0.01; //magic number need redoing in the function to be % of aim.

	
private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;

};
