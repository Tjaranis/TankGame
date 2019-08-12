// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	if (!TankRoot)
	{
		Ini();
	}
	//auto _name = GetName();
	////remember to clamp values to avoid changing beyound max
	//UE_LOG(LogTemp, Warning, TEXT("%s this track throttle; %f"), *_name, Throttle);
	auto ForceAppliedd = GetForwardVector() * Throttle * Maxforce;
	auto ForceLocation = GetComponentLocation();
	TankRoot->AddForceAtLocation(ForceAppliedd, ForceLocation);

	/*not working as wanted //TODO remove/fix this
	auto TankRotator = TankRoot->GetComponentRotation();

	if (TankRotator.Yaw > MaxDegreesTankTips) {
		TankRotator.Yaw = MaxDegreesTankTips;
	}if (TankRotator.Roll > MaxDegreesTankTips) {
		TankRotator.Roll = MaxDegreesTankTips;
	}if (TankRotator.Pitch > MaxDegreesTankTips) {
		TankRotator.Pitch = MaxDegreesTankTips;
	}if (TankRotator.Yaw > -MaxDegreesTankTips) {
		TankRotator.Yaw = -MaxDegreesTankTips;
	}if (TankRotator.Roll > -MaxDegreesTankTips) {
		TankRotator.Roll = -MaxDegreesTankTips;
	}if (TankRotator.Pitch > -MaxDegreesTankTips) {
		TankRotator.Pitch = -MaxDegreesTankTips;
	}
	*/
	//UE_LOG(LogTemp, Warning, TEXT("%s weight; %f"), *_name, TankMass);
}


// Called when the game starts or when spawned
void UTankTrack::Ini()
{
	TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());;
	TankMass = TankRoot->GetMass();
	Maxforce = TankMass * Accelleration;
}