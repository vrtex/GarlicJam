// GarlicJam 2019

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainHeroController.generated.h"


/**
 * 
 */
UCLASS()
class GARLICJAM_API AMainHeroController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void updateDirection(FVector direction);

	void Possess(APawn* PawnToPossess) override;

	UFUNCTION(BlueprintImplementableEvent)
		void changeCamera();



	
protected:
	UPROPERTY(BlueprintReadOnly)
		class AMainHero * controlledHero = nullptr;
};
