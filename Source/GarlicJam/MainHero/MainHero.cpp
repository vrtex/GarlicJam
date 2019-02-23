// GarlicJam 2019

#include "MainHero.h"


// Sets default values
AMainHero::AMainHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainHero::updateDirection(FVector direction)
{
	AddMovementInput(direction.GetSafeNormal());
}