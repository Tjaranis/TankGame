// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankTrack.h"
#include "TankMovementComponent.generated.h"


/**
 * Responsible for giving input to track to drive forward/backwards with single input.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	//setup
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);
	//move functions
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float input);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendMoveLeft(float input);

private:
	UTankTrack *LeftTrack=nullptr;
	UTankTrack *RightTrack= nullptr;
};
