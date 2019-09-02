// Footlights, 2019

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  // must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	// Called every frame
	// virtual passes this function down to children
	// override checks if this function is in one of the parents
	virtual void Tick(float DeltaTime) override;
 
	// start the tank moving the barrel so that a shot would
	// hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	FVector HitLocation();

	// return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)   //creates editable dropdown box in details > Tank Player Controller
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)   //creates editable dropdown box in details > Tank Player Controller
		float CrossHairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
