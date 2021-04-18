// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = GetRelativeRotation().Yaw + RotationChange;
	RawNewElavation = FMath::Clamp<float>(RawNewElavation, MinRotationDegrees, MaxRotationDegrees);
	SetRelativeRotation(FRotator(0, RawNewElavation, 0));
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Rotating at  %f"), Time, RawNewElavation);
}