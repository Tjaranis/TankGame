// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "BattleTank.h"
#include "Tank.h"

ATank* ATankPlayerController::GetControllerTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("test"));
	auto ControlledTank = GetControllerTank();


	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PController ticktick"));
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) { return; }

	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation)) { //going to line trace
		GetControllerTank()->AimAt(HitLocation);
		//aim at point
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("getsightmethod: %s"), *ScreenLocation.ToString());

	//Deproject screen position.
	FVector LookDirection;
	if (GetLookLocation(ScreenLocation, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());

		//line along look direction (hit/miss target)
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return nullptr;
}

bool ATankPlayerController::GetLookLocation(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	
	if(GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility)
	)
		{
		HitLocation = HitResult.Location;
		return true;
		}
	
	HitLocation = FVector(0);
	return false;
	
}
