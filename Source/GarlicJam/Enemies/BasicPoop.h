// GarlicJam 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicPoop.generated.h"

class USphereComponent;

UCLASS()
class GARLICJAM_API ABasicPoop : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicPoop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent * detectionSphere;




	UFUNCTION(BlueprintCallable)
		void checkForTarget();
	
	
};
