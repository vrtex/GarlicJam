// GarlicJam 2019

#include "MainHeroController.h"
#include "MainHero/MainHero.h"



void AMainHeroController::updateDirection(FVector direction)
{
	if(!controlledHero)
		return;
	controlledHero->updateDirection(direction);
	// controlledHero->AddMovementInput(direction.GetSafeNormal());
}

void AMainHeroController::Possess(APawn * PawnToPossess)
{
	Super::Possess(PawnToPossess);
	controlledHero = Cast<AMainHero>(PawnToPossess);
	if(!controlledHero)
		UE_LOG(LogTemp, Error, TEXT("Can't find hero"));
	changeCamera();
}