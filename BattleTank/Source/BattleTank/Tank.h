// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Paste new includes above this

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		int32 StartingHealth = 200;
	UPROPERTY(VisibleAnywhere, Category = "Damage")
		int32 CurrentHealth = StartingHealth;
	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercentage() const;
};
