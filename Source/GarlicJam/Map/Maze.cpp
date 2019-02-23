// GarlicJam 2019

#include "Maze.h"


TArray<Node*> Node::getNeighbours() const
{
	TArray<Node *> toReturn;

	if(left && !left->visited) toReturn.Add(left);
	if(right && !right->visited) toReturn.Add(right);
	if(up && !up->visited) toReturn.Add(up);
	if(down && !down->visited) toReturn.Add(down);

	return toReturn;
}

Node * Node::getRandomNext() const
{
	TArray<Node *> neigh = getNeighbours();

	if(neigh.Num() == 0)
		return nullptr;

	int32 index = FMath::RandRange(0, neigh.Num() - 1);

	return neigh[index];
}

void Node::deleteWallTo(Node * next)
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
	TArray<Node *> maze;
	for(int32 y = 0; y < ySize; ++y)
	{
		for(int32 x = 0; x < xSize; ++x)
		{
			maze.Push(new Node(x, y));
		}
	}


	for(Node * e : maze)
	{
		int32 index = e->x + e->y * xSize;
		if(e->x > 0)
			e->left = maze[index - 1];
		if(e->x < xSize - 2)
			e->right = maze[index + 1];
		if(e->y > 0)
			e->up = maze[index - xSize];
		if(e->y < ySize - 2)
			e->down = maze[index + xSize];
	}

	TArray<Node *> unvisited = maze;
	TArray<Node *> path;

	Node * current = maze[0];
	current->visited = true;
	unvisited.Remove(current);

	while(unvisited.Num() > 0)
	{
		Node * nextCell = current->getRandomNext();

		if(nextCell)
		{
			path.Push(current);
			current->deleteWallTo(nextCell);
			current = nextCell;
			current->visited = true;
			unvisited.Remove(current);
		}
		else
			current = path.Pop();
	}
	UE_LOG(LogTemp, Warning, TEXT("Size: %i"), maze.Num());
	return;

	for(Node * e : maze)
		AddTile(e->x, e->y, e->wallLeft, e->wallRight, e->wallUp, e->wallDown);

	for(Node * e : maze)
		delete e;
}