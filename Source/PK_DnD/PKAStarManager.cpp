// Fill out your copyright notice in the Description page of Project Settings.

#include "PKAStarManager.h"
#include "PKAStarNode.h"

APKAStarManager::APKAStarManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APKAStarManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AStarManager BeginPlay called"));

	// Initialize the grid and set start and goal locations
	InitializeGrid(10, 10);
	StartLocation = FVector(0, 0, 0);
	GoalLocation = FVector(900, 900, 0);

	UE_LOG(LogTemp, Warning, TEXT("Calling AStar with Start: %s, Goal: %s"), *StartLocation.ToString(), *GoalLocation.ToString());
	AStar(StartLocation, GoalLocation);
}

void APKAStarManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawGrid();
	DrawPath();
}

void APKAStarManager::InitializeGrid(int32 GridSizeX, int32 GridSizeY)
{
	Nodes.Empty();

	for (int32 x = 0; x < GridSizeX; x++)
	{
		for (int32 y = 0; y < GridSizeY; y++)
		{
			UPKAStarNode* NewNode = NewObject<UPKAStarNode>();
			NewNode->Position = FVector(x * 100, y * 100, 50);
			NewNode->bIsWalkable = true;
			Nodes.Add(NewNode);
		}
	}
}

void APKAStarManager::AStar(FVector Start, FVector Goal)
{
	// Collection of nodes that are yet to be evaluated
	TArray<UPKAStarNode*> OpenSet;
	// Collection of nodes that have already been evaluated
	TArray<UPKAStarNode*> ClosedSet;

	UPKAStarNode* StartNode = NewObject<UPKAStarNode>();
	StartNode->Position = Start;
	OpenSet.Add(StartNode);

	UE_LOG(LogTemp, Warning, TEXT("Starting A* Algorithm"));

	while (OpenSet.Num() > 0)
	{
		UPKAStarNode* CurrentNode = OpenSet[0];

		// Find the node with the lowest F cost
		for (UPKAStarNode* Node : OpenSet)
		{
			if (Node->FCost() < CurrentNode->FCost() || (Node->FCost() == CurrentNode->FCost() && Node->HCost < CurrentNode->HCost))
			{
				CurrentNode = Node;
			}
		}

		OpenSet.Remove(CurrentNode);
		ClosedSet.Add(CurrentNode);

		UE_LOG(LogTemp, Warning, TEXT("Processing Node at: %s"), *CurrentNode->Position.ToString());

		// Checks if the position of the CurrentNode is equal to the Goal position
		if (CurrentNode->Position.Equals(Goal, 1.0f))
		{
			// Traces back the path from the goal to the start
			while (CurrentNode != nullptr)
			{
				Path.Add(CurrentNode->Position);
				CurrentNode = CurrentNode->Parent;
			}
			Algo::Reverse(Path);

			// Log the path points
			for (const FVector& Point : Path)
			{
				UE_LOG(LogTemp, Warning, TEXT("Path Point: %s"), *Point.ToString());
			}
			return;
		}

		// Generate neighbors
		TArray<UPKAStarNode*> Neighbors = GetNeighbors(CurrentNode);

		for (UPKAStarNode* Neighbor : Neighbors)
		{
			// Skip if the neighbor is not walkable or has already been evaluated
			if (!Neighbor->bIsWalkable || ClosedSet.Contains(Neighbor)) continue;

			// Calculate the tentative GCost from the current node to the neighbor
			float TentativeGCost = CurrentNode->GCost + FVector::Dist(CurrentNode->Position, Neighbor->Position);

			// Check if the neighbor is not in the OpenSet
			if (!OpenSet.Contains(Neighbor))
			{
				OpenSet.Add(Neighbor); // Add the neighbor to the OpenSet for evaluation
			}
			// If the neighbor is already in the OpenSet, check if the new GCost is lower
			else if (TentativeGCost >= Neighbor->GCost)
			{
				continue; // Skip this neighbor if the new GCost is not better
			}

			// Update the neighbor's properties
			Neighbor->Parent = CurrentNode; // Set the current node as the parent
			Neighbor->GCost = TentativeGCost; // Update the GCost
			Neighbor->HCost = FVector::Dist(Neighbor->Position, Goal); // Calculate the HCost
		}
	}

	// Log if no path is found
	UE_LOG(LogTemp, Warning, TEXT("No path found from Start: %s to Goal: %s"), *Start.ToString(), *Goal.ToString());
}

TArray<UPKAStarNode*> APKAStarManager::GetNeighbors(UPKAStarNode* CurrentNode)
{
	TArray<UPKAStarNode*> Neighbors;

	// Making some non-walkable nodes
	Nodes[5]->bIsWalkable = false;
	Nodes[6]->bIsWalkable = false;

	for (UPKAStarNode* Node : Nodes)
	{
		// Check if the node is within a certain distance
		if (FVector::Dist(CurrentNode->Position, Node->Position) < 150.0f && Node != CurrentNode)
		{
			Neighbors.Add(Node);
		}
	}

	return Neighbors;
}

void APKAStarManager::DrawGrid()
{
	for (UPKAStarNode* Node : Nodes)
	{
		FColor NodeColor = Node->bIsWalkable ? FColor::Green : FColor::Red;
		DrawDebugPoint(GetWorld(), Node->Position, 20.0f, NodeColor, true, 1.f, 0);
	}
}

void APKAStarManager::DrawPath()
{
	if (Path.Num() > 0)
	{
		for (int32 i = 0; i < Path.Num() - 1; i++)
		{
			DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Blue, true, 1.f, 0, 5);
		}
	}
}