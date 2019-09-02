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

public:
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

};
