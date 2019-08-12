// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Tank.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Sets the throttle/speed of the track
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	UFUNCTION(BlueprintCallable, Category = Initialize)
	void Ini();

	//max force

	UPROPERTY(EditDefaultsOnly,Category = Stats)
		float Maxforce=400000; //400.000kg/40tons - 1g accel
	//TODO do proper accelleration*mass input from parent socket mass
	UPROPERTY(EditDefaultsOnly, Category = Stats)
		float Accelleration = 2000;
	
	float TankMass;

	UPrimitiveComponent *TankRoot;

	/*
	UPROPERTY(EditDefaultsOnly, Category = Stats)
		float MaxDegreesTankTips = 45;
	*/
};
