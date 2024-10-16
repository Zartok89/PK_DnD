// Fill out your copyright notice in the Description page of Project Settings.

#include "PKGraphNode.h"

// Sets default values
APKGraphNode::APKGraphNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void APKGraphNode::BeginPlay()
{
	Super::BeginPlay();

	// Draw lines to neighbor nodes
	for (APKGraphNode* Neighbor : Neighbors)
	{
		if (Neighbor)
		{
			DrawDebugLine(
				GetWorld(),
				GetActorLocation(),
				Neighbor->GetActorLocation(),
				FColor::Green,
				true,
				-1.0f,
				0,
				5.0f
			);
		}
	}
}

void APKGraphNode::AddNeighbor(APKGraphNode* Neighbor)
{
	if (Neighbor && !Neighbors.Contains(Neighbor))
	{
		Neighbors.Add(Neighbor);
	}
}