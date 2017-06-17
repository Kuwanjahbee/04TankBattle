// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //generated.h must be the last include

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//start the tank to move the barrel so a shot
	//will hit where the crosshair intersects world
	void AimTowardsCrosshair();

	//return and out Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
