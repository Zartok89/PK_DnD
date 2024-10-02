// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKDNDTreeManager.generated.h"

class APKDNDTreeNode;

UCLASS()
class PK_DND_API APKDNDTreeManager : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Default Constructor
	APKDNDTreeManager();

	virtual void Tick(float DeltaTime) override;

	/*
	 * Functions
	 */
	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void BuildTree();

	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void CreateChildren(APKDNDTreeNode* ParentNode, int32 CurrentDepth, int32 MaxDepth);

	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void DepthFirstTraversal();
	void DepthFirstTraversalHelper(APKDNDTreeNode* Node, TArray<APKDNDTreeNode*>& TraversalNodes);

	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void BreadthFirstTraversal();
	void StartColorChangeSequence(const TArray<APKDNDTreeNode*>& Nodes, FLinearColor Color);


	/*
	 * Variables
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	APKDNDTreeNode* mRootNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	int32 mMaxDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	float mObjectSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	TSubclassOf<AActor> NodeObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	float ColorDelayInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	FLinearColor BreadthSearchColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	FLinearColor DepthSearchColor;
};
