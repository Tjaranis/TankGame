// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Tank.h"

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("test"));
	auto ControlledTank = GetControllerTank();
	PlayerTank = GetPlayerTank();
	
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank) {

		MoveToActor(PlayerTank, AcceptanceRadius);
		GetControllerTank()->AimAt(PlayerTank->GetActorLocation());
			//auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: barrel aligned in AI component:"), Time);
		GetControllerTank()->Fire();
	}
	

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn(); //player need to be spawned at load of tank or it returns null
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
	
}






