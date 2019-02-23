// GarlicJam 2019

#include "Maze.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Map/Tile.h"


TArray<FMazeNode*>FMazeNode::getNeighbours() const
{
	TArray<FMazeNode *> toReturn;

	if(left) toReturn.Add(left);
	if(right) toReturn.Add(right);
	if(up) toReturn.Add(up);
	if(down) toReturn.Add(down);

	return toReturn;
}

FMazeNode *FMazeNode::getRandomNext() const
{
	TArray<FMazeNode *> neigh = getNeighbours();

	if(neigh.Num() == 0)
		return nullptr;

	int32 index = FMath::RandRange(0, neigh.Num() - 1);

	return neigh[index];
}

void FMazeNode::deleteWallTo(FMazeNode * next)
{
	if(next == left)
	{
		wallLeft = false;
		next->wallRight = false;
	}
	if(next == right)
	{
		wallRight = false;
		next->wallLeft = false;
	}
	if(next == up)
	{
		wallUp = false;
		next->wallDown = false;
	}
	if(next == down)
	{
		wallDown = false;
		next->wallUp = false;
	}
}


//-----------------------------------

// Sets default values
AMaze::AMaze()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaze::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMaze::generateMaze()
{
	for(int32 y = 0; y < ySize; ++y)
	{
		for(int32 x = 0; x < xSize; ++x)
		{
			maze.Push(FMazeNode(x, y));
		}
	}



	for(FMazeNode e : maze)
	{
		int32 index = e.x + e.y * xSize;
		if(e.x > 0)
			e.left = &maze[index - 1];
		if(e.x < xSize - 2)
			e.right = &maze[index + 1];
		if(e.y > 0)
			e.up = &maze[index - xSize];
		if(e.y < ySize - 2)
			e.down = &maze[index + xSize];
	}



	TArray<FMazeNode *> path;

	FMazeNode * current = &maze[0];

	while(current)
	{
		FMazeNode * nextCell = current->getRandomNext();

		if(nextCell)
		{
			path.Push(current);
			current->deleteWallTo(nextCell);
			current = nextCell;
		}
		else if(path.Num() > 0)
			current = path.Pop();
		else
			current = nullptr;
	}

	/*
	for(FMazeNode e : maze)
		AddTile(e.x, e.y, e.wallLeft, e.wallRight, e.wallUp, e.wallDown);
	*/


	TArray<ATile *> tiles;
	for(int32 y = 0; y < ySize; ++y)
	{
		for(int32 x = 0; x < xSize; ++x)
		{
			tiles.Add(GetWorld()->SpawnActor<ATile>(tileClass.Get(), GetActorTransform()));
		}
	}

	for(int32 y = 0; y < ySize; ++y)
	{
		for(int32 x = 0; x < xSize; ++x)
		{
			int32 index = x + xSize * y;
			ATile * current = tiles[index];
			if(index > 0)
				current->left = tiles[index - 1];
			if(index < xSize - 1)
				current->right = tiles[index + 1];
			if(index < ySize - 1)
				current->up = tiles[index + xSize];
			if(index > xSize)
				current->down = tiles[index - xSize];
		}
	}

	tiles[0]->test();
	tiles[0]->alignUp();

}