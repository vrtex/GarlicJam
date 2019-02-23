// GarlicJam 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UStaticMeshComponent;
class UStaticMesh;

UCLASS()
class GARLICJAM_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintReadOnly)
		USceneComponent * Root;
	UPROPERTY(BlueprintReadOnly)
		ATile * left = nullptr;
	UPROPERTY(BlueprintReadOnly)
		ATile * right = nullptr;
	UPROPERTY(BlueprintReadOnly)
		ATile * up = nullptr;
	UPROPERTY(BlueprintReadOnly)
		ATile * down = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMesh * blockMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent * UpWall = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent * DownWall = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent * LeftWall = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent * RightWall = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent * LeftAttachPoint = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent * RightAttachPoint = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent * UpAttachPoint = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent * DownAttachPoint = nullptr;

	UFUNCTION(BlueprintPure)
		FTransform getLeftAttachPoint();
	UFUNCTION(BlueprintPure)
		FTransform getRightAttachPoint();
	UFUNCTION(BlueprintPure)
		FTransform getUpAttachPoint();
	UFUNCTION(BlueprintPure)
		FTransform getDownAttachPoint();

	UFUNCTION(BlueprintCallable)
		void alignUp();

	UFUNCTION(BlueprintCallable)
		void alignRight();

	void test();
	
	
};
