// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank: %s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller isnot possessing any tank."));
	}

	auto PlayerTank = GetPlayerTank();
	if(PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank got the Player Tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank failed to get Player Tank."));
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank)
		return Cast<ATank>(PlayerTank);
	else
		return nullptr;
}
