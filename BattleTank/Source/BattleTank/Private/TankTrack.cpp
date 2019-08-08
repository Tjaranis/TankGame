// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	auto _name = GetName();
	//remember to clamp values to avoid changing beyound max
	UE_LOG(LogTemp, Warning, TEXT("%s this track throttle; %f"), *_name, Throttle);
}