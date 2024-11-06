// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKAStarManager.generated.h"

class UPKAStarNode;
class APKAStarCharacter;

UCLASS()
class PK_DND_API APKAStarManager : public AActor
{
	GENERATED_BODY()

public:
	APKAStarManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

    void InitializeGrid(int32 GridSizeX, int32 GridSizeY);  
    void AStar(FVector Start, FVector Goal);  
    TArray<UPKAStarNode*> GetNeighbors(UPKAStarNode* CurrentNode);  
    void DrawGrid();  
    void DrawPath();  

	/*
	 * Member Variables
	 */
	TArray<UPKAStarNode*> Nodes;
    TArray<FVector> Path;  
    FVector StartLocation;  
    FVector GoalLocation; 

 
};
