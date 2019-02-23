// GarlicJam 2019

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BasicPoopController.generated.h"

class UBlackboardData;

/**
 * 
 */
UCLASS()
class GARLICJAM_API ABasicPoopController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	
	virtual void Possess(APawn* aPawn) override;


	UPROPERTY(EditAnywhere)
		UBlackboardData * bb;
	UPROPERTY(EditAnywhere)
		UBehaviorTree * bt;
};
