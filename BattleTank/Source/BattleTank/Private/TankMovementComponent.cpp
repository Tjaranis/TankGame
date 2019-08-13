// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float input) {
	//remember to clamp values to avoid changing beyound max
	//UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward; %f"), input);
	LeftTrack->SetThrottle(input);
	RightTrack->SetThrottle(input);
}
void UTankMovementComponent::IntendMoveLeft(float input) {
	//remember to clamp values to avoid changing beyound max
	//UE_LOG(LogTemp, Warning, TEXT("IntendMoveLeft; %f"), input);
		LeftTrack->SetThrottle(-input);
		RightTrack->SetThrottle(input);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//no need to call super as we are changing functionality; and need the input gained here.

	auto TankName = GetOwner()->GetName();
	auto _MoveVelocity = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to ; %s"), *TankName,*_MoveVelocity);
}

void UTankMovementComponent::Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) {
		UE_LOG(LogTemp, Warning, TEXT("LeftTrackToSet or RightTrackToSet unexpected void ref; "));
		return;
	}
	else {
		LeftTrack = LeftTrackToSet;
		RightTrack = RightTrackToSet;
	}

}