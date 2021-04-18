// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = GetRelativeRotation().Pitch + ElevationChange;
	RawNewElavation = FMath::Clamp<float>(RawNewElavation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(RawNewElavation, 0, 0));
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Elavating at a speed %f"), Time, RawNewElavation);
}