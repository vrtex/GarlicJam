// GarlicJam 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Maze.generated.h"

class ATile;

USTRUCT(BlueprintType, Blueprintable)
struct FMazeNode
{
	GENERATED_BODY()

	FMazeNode() {}
	FMazeNode(int x, int y) { this->x = x; this->y = y; }
		int32 x;
		int32 y;
	FMazeNode * left = nullptr,* right = nullptr, * up = nullptr, * down = nullptr;
	bool wallLeft = true, wallRight = true, wallUp = true, wallDown = true;

	TArray<FMazeNode *> getNeighbours() const;

	FMazeNode * getRandomNext() const;

	void deleteWallTo(FMazeNode * next);
};

UCLASS()
class GARLICJAM_API AMaze : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaze();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void generateMaze();

	UFUNCTION(BlueprintImplementableEvent)
		void AddTile(int32 x, int32 y, bool leftWall, bool rightWall, bool upWall, bool downWall);

protected:
	UPROPERTY(BlueprintReadOnly)
		TArray<FMazeNode> maze;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATile> tileClass;

	UPROPERTY(EditAnywhere)
		int32 xSize;
	UPROPERTY(EditAnywhere)
		int32 ySize;

	
};
