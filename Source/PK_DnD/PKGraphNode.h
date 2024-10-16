// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKGraphNode.generated.h"

UCLASS()
class PK_DND_API APKGraphNode : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APKGraphNode();

	void AddNeighbor(APKGraphNode* Neighbor);

	/*
	 * Variables
	 */
	UPROPERTY(VisibleAnywhere, Category = "GraphNode")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphNode")
	TArray<APKGraphNode*> Neighbors;

protected:
	virtual void BeginPlay() override;
};
