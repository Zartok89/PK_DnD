// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PKAStarNode.generated.h"

/**
 *
 */
UCLASS()
class PK_DND_API UPKAStarNode : public UObject
{
	GENERATED_BODY()

public:
	// Constructor
	UPKAStarNode();

	// Position of the node
	FVector Position;

	// Cost from start node
	float GCost;

	// Heuristic cost to goal node
	float HCost;

	// Parent node in the path
	UPROPERTY()
	UPKAStarNode* Parent;

	// Check if node is not blocked by an obstacle
	bool bIsWalkable;

	float FCost() const { return GCost + HCost; }
};
