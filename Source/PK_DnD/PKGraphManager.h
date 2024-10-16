// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKGraphManager.generated.h"

class APKGraphNode;
class APKPathCharacter;

UCLASS()
class PK_DND_API APKGraphManager : public AActor
{
	GENERATED_BODY()

public:
	APKGraphManager();

	UFUNCTION(BlueprintCallable, Category = "GraphManager")
	TArray<APKGraphNode*> FindShortestPath();

	/*
	 * Variables
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphManager")
	TArray<APKGraphNode*> AllNodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphManager")
	APKGraphNode* StartNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphManager")
	APKGraphNode* EndNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GraphManager")
	APKPathCharacter* PathCharacter;

protected:
	virtual void BeginPlay() override;
};
