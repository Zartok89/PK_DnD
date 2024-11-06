// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKDNDTreeNode.generated.h"

//class UStaticMeshComponent;

UCLASS()
class PK_DND_API APKDNDTreeNode : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Default Constructor
	APKDNDTreeNode();

	virtual void Tick(float DeltaTime) override;

	/*
	 * Functions
	 */
	UFUNCTION(BlueprintCallable, Category = "TreeNode")
	void AddChild(APKDNDTreeNode* ChildNode);

	// ---- DO NOT WORRIE ABOUT THE STUFF IN HERE ----
	UFUNCTION(BlueprintCallable, Category = "TreeNode")
	void SetNodeColor(const FLinearColor& NewColor);
	// ------------------------------------------------

	/*
	 * Variables
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	int32 mData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	int32 mMaxChildren;

	// ---- Extra stuff for Unreal ----
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	TArray<APKDNDTreeNode*> mChildren;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	UStaticMeshComponent* MeshComponent;
	// ----------------------------------
};
