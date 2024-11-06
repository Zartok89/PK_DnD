// Fill out your copyright notice in the Description page of Project Settings.

#include "PKGraphManager.h"
#include "PKGraphNode.h"
#include "PKPathCharacter.h"

// Sets default values
APKGraphManager::APKGraphManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void APKGraphManager::BeginPlay()
{
	Super::BeginPlay();

	if (PathCharacter)
	{
		TArray<APKGraphNode*> Path = FindShortestPath();
		if (Path.Num() > 0)
		{
			PathCharacter->SetPath(Path);
			PathCharacter->StartMoving();
		}
	}
}

TArray<APKGraphNode*> APKGraphManager::FindShortestPath()
{
	TArray<APKGraphNode*> Path;

	if (!StartNode || !EndNode)
	{
		return Path;
	}

	TQueue<APKGraphNode*> Queue;
	TMap<APKGraphNode*, APKGraphNode*> Visited;

	Queue.Enqueue(StartNode);
	Visited.Add(StartNode, nullptr);

	while (!Queue.IsEmpty())
	{
		APKGraphNode* CurrentNode;
		Queue.Dequeue(CurrentNode);

		if (CurrentNode == EndNode)
		{
			APKGraphNode* Node = EndNode;
			while (Node)
			{
				Path.Insert(Node, 0);
				Node = Visited[Node];
			}
			break;
		}

		for (APKGraphNode* Neighbor : CurrentNode->Neighbors)
		{
			if (!Visited.Contains(Neighbor))
			{
				Queue.Enqueue(Neighbor);
				Visited.Add(Neighbor, CurrentNode);
			}
		}
	}

	return Path;
}