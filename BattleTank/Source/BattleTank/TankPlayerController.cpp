// Footlights, 2019

#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	// UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;  // out parameter

	if (GetSightRayHitLocation(HitLocation))  // has "side effect", is going to line trace
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look direction is: %s"), *HitLocation.ToString());

		// TODO tell controlled tank to aim at this point
	}
}

// get world location with linetrace thru crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// OutHitLocation = FVector(1.0);
	// find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	// UE_LOG(LogTemp, Warning, TEXT("Screen Location is: %s"), *ScreenLocation.ToString());

	// "de-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	FVector WorldDirection;

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction is: %s"), *WorldDirection.ToString());
	}
	
	// line trace along that look direction, and see what we hit (up to max range)
	return true;

}