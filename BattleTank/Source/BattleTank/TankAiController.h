// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
	public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		UTankAimingComponent* AimingComponent = nullptr;
	private:
		//How close can the AI tank get
		float AcceptanceRadius = 3000;

};
