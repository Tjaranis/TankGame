// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float input) {
	//remember to clamp values to avoid changing beyound max
	UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward; %f"), input);
}
void UTankMovementComponent::IntendMoveBackward(float input) {
	//remember to clamp values to avoid changing beyound max
	UE_LOG(LogTemp, Warning, TEXT("IntendMoveForward; %f"), input);
}