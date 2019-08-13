// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank * GetControllerTank() const;
	virtual void BeginPlay() override;
	ATank * GetPlayerTank() const;
	
private:
	ATank *PlayerTank;
	//how close wil the ai tank move to the player in cm
	float AcceptanceRadius = 3000;
};
