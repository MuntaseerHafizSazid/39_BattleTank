// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		UTankAimingComponent* AimingComponent = nullptr;

		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
			void FoundAimingComponent(UTankAimingComponent* AimingComponentReference);

		virtual void SetPawn(APawn* InPawn) override;
	private:
		UPROPERTY(EditAnywhere)
			float CrossHairXLocation = 0.5;
		UPROPERTY(EditAnywhere)
			float CrossHairYLocation = 0.33;
		UPROPERTY(EditAnywhere)
			float LineTraceRange = 1000000;

		void AimTowardsCrosshair();
		bool GetSightRayHitLocation(FVector& HitLocation) const;
		bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

		UFUNCTION()
			void OnPossessedTankDeath();
	
};
