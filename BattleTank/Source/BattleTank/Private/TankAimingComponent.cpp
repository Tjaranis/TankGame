// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	if (!Barrel) { return; }
	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	/*auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation.ToString());
	*/
	MoveBarrel(AimDirection(HitLocation, LaunchSpeed));
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) return;
	Barrel = BarrelToSet;

}
void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	if (!TurretToSet) return;
	Turret = TurretToSet;
}

FVector UTankAimingComponent::AimDirection(FVector HitLocation, float LaunchSpeed) {
	FVector OutLaunchVelocity(0, 0, 0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0.f, 0, ESuggestProjVelocityTraceOption::DoNotTrace
	);
	
	FVector LaunchDirectionVector = OutLaunchVelocity.GetSafeNormal();
	return LaunchDirectionVector;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotator - BarrelRotation;
	/*
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s"), *AimAsRotator.ToString());
	*/
	Barrel->Elevate(DeltaRotation.Pitch);
	if (FMath::Abs(DeltaRotation.Yaw) < 180) {
		Turret->Rotate(DeltaRotation.Yaw);
	}
	else{ Turret->Rotate(-DeltaRotation.Yaw); }

	if ((DeltaRotation.Pitch > -AccuracySpread && DeltaRotation.Pitch < AccuracySpread) 
		|| (DeltaRotation.Yaw > -AccuracySpread && DeltaRotation.Yaw < AccuracySpread)) {
		BarrelAlignedWithTarget = true;

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: barrel aligned in aiming component:"), Time);
	}else { BarrelAlignedWithTarget = false; }

}

