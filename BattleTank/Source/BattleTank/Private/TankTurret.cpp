// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	/*
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Turret elevate() called at speed %f"), Time, RelativeSpeed);
	*/
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));

}