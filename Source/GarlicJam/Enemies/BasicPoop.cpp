// GarlicJam 2019

#include "BasicPoop.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "MainHero/MainHero.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"

// Sets default values
ABasicPoop::ABasicPoop()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	detectionSphere = CreateDefaultSubobject<USphereComponent>(FName("Detection sphere"));
	detectionSphere->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ABasicPoop::BeginPlay()
{
	Super::BeginPlay();
	
	// detectionSphere->OnComponentBeginOverlap().AddDynamic(this, &ABasicPoop::OnBeginOverlap);
}

// Called every frame
void ABasicPoop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicPoop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicPoop::checkForTarget()
{
	TArray<AActor *> actors;
	detectionSphere->GetOverlappingActors(actors);
	for(auto a : actors)
	{
		AMainHero * hero = Cast<AMainHero>(a);
		if(!hero)
			continue;

		UE_LOG(LogTemp, Warning, TEXT("%i"), actors.Num());
		Cast<AAIController>(GetController())->GetBlackboardComponent()->SetValueAsObject(FName("TargetHero"), Cast<APawn>(hero));
		return;
	}
	Cast<AAIController>(GetController())->GetBlackboardComponent()->ClearValue(FName("TargetHero"));
}
