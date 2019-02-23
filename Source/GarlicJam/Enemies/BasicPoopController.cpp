// GarlicJam 2019

#include "BasicPoopController.h"




void ABasicPoopController::BeginPlay()
{
	Super::BeginPlay();
	UBlackboardComponent * BBComp = GetBlackboardComponent();
	UseBlackboard(bb, BBComp);
	RunBehaviorTree(bt);
}

void ABasicPoopController::Possess(APawn * PawnToPossess)
{
	Super::Possess(PawnToPossess);


}