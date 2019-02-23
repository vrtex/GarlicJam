// GarlicJam 2019

#include "Tile.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateAbstractDefaultSubobject<USceneComponent>(FName("Root"));
	RootComponent = Root;

	UpWall = CreateDefaultSubobject<UStaticMeshComponent>(FName("Up wall"));
	UpWall->SetupAttachment(GetRootComponent());
	DownWall = CreateDefaultSubobject<UStaticMeshComponent>(FName("Down wall"));
	DownWall->SetupAttachment(GetRootComponent());
	LeftWall = CreateDefaultSubobject<UStaticMeshComponent>(FName("Left wall"));
	LeftWall->SetupAttachment(GetRootComponent());
	RightWall= CreateDefaultSubobject<UStaticMeshComponent>(FName("Right wall"));
	RightWall->SetupAttachment(GetRootComponent());

	UpAttachPoint = CreateDefaultSubobject<USceneComponent>(FName("Up attach point"));
	UpAttachPoint->SetupAttachment(GetRootComponent());
	DownAttachPoint = CreateDefaultSubobject<USceneComponent>(FName("Down attach point"));
	DownAttachPoint->SetupAttachment(GetRootComponent());
	LeftAttachPoint = CreateDefaultSubobject<USceneComponent>(FName("Left attach point"));
	LeftAttachPoint->SetupAttachment(GetRootComponent());
	RightAttachPoint = CreateDefaultSubobject<USceneComponent>(FName("Right attach point"));
	RightAttachPoint->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	if(!blockMesh)
		return;
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform ATile::getLeftAttachPoint()
{
	return LeftAttachPoint->GetComponentTransform();
}

FTransform ATile::getRightAttachPoint()
{
	return RightAttachPoint->GetComponentTransform();
}

FTransform ATile::getUpAttachPoint()
{
	return UpAttachPoint->GetComponentTransform();
}

FTransform ATile::getDownAttachPoint()
{
	return DownAttachPoint->GetComponentTransform();
}

void ATile::alignUp()
{
	ATile * current = up;
	ATile * previous = this;
	while(current)
	{
		FTransform trans = previous->getUpAttachPoint();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *trans.ToString());
		current->SetActorTransform(previous->getUpAttachPoint());
		current->alignRight();
		previous = current;
		current = current->up;
	}

}

void ATile::alignRight()
{
	ATile * current = right;
	ATile * previous = this;
	while(current)
	{
		current->SetActorTransform(previous->getRightAttachPoint());
		previous = current;
		current = current->right;
	}
}

void ATile::test()
{
	if(up)
		UE_LOG(LogTemp, Warning, TEXT("up"));
	if(down)
		UE_LOG(LogTemp, Warning, TEXT("down"));
	if(left)
		UE_LOG(LogTemp, Warning, TEXT("left"));
	if(right)
		UE_LOG(LogTemp, Warning, TEXT("right"));
}