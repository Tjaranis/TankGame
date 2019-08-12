// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
//#include "Engine/World.h" //needed for UE_LOG getworld only
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

bool ATank::AimingAtTarget()
{
	return BarrelAlignedToTarget;
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	 
	//no need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	BarrelAlignedToTarget = TankAimingComponent->BarrelAlignedWithTarget;
}

//fire projectile 1.
void ATank::Fire()
{
	/*
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fires:"), Time);
	*/
	if (!Barrel) return;//should be moved to initialise as it is a one time check
	
	bool isReloaded = (FPlatformTime::Seconds() - LastFired) > ReloadTimeSecond;
	
	if(isReloaded){
		LastFired = (FPlatformTime::Seconds());
			
		//spawn a projectile at the socket location of barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);	
	}
}

