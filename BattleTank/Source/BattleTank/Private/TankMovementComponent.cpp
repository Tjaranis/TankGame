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

	
	auto _TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto _MoveDirectionVector = MoveVelocity.GetSafeNormal();
	auto _ForwordMovement = FVector::DotProduct(_TankForwardDirection, _MoveDirectionVector);
	auto _Rotation = FVector::CrossProduct(_TankForwardDirection, _MoveDirectionVector).Z;

	IntendMoveForward(_ForwordMovement);
	IntendMoveLeft(_Rotation);

	/*
	auto TankName = GetOwner()->GetName();
	auto MoveDirectionVector = MoveVelocity.GetSafeNormal().ToString();
	*/
	UE_LOG(LogTemp, Warning, TEXT("%s ForwardDirection and forward movement ; %f"), *_TankForwardDirection.ToString(), _ForwordMovement);
	UE_LOG(LogTemp, Warning, TEXT("%s ForwardDirection and rotation ; %f"), *_TankForwardDirection.ToString(), _Rotation);
}

void UTankMovementComponent::SetTrack(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
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

// Called when the game starts or when spawned
void UTankMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}