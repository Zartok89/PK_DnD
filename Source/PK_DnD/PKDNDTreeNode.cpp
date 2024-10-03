// Fill out your copyright notice in the Description page of Project Settings.

#include "PKDNDTreeNode.h"

APKDNDTreeNode::APKDNDTreeNode()
{
	PrimaryActorTick.bCanEverTick = true;


	// ---- Extra stuff for Unreal ----
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	// ----------------------------------


	mData = 0;
	mMaxChildren = 2;
}

void APKDNDTreeNode::BeginPlay()
{
	Super::BeginPlay();
}

void APKDNDTreeNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ---- Extra stuff for Unreal ----
	for (APKDNDTreeNode* Child : mNodeChildren)
	{
		if (Child)
		{
			DrawDebugLine(GetWorld(), GetActorLocation(), Child->GetActorLocation(), FColor::Green, false, -1.f, 0, 5.f);
		}
	}
	// ----------------------------------
}

void APKDNDTreeNode::AddChild(APKDNDTreeNode* ChildNode)
{
	if (mNodeChildren.Num() < mMaxChildren && ChildNode)
	{
		mNodeChildren.Add(ChildNode);
	}
}


// ---- DO NOT WORRIE ABOUT THE STUFF BELOW ----
void APKDNDTreeNode::SetNodeColor(const FLinearColor& NewColor)
{
	if (MeshComponent)
	{
		UMaterialInstanceDynamic* DynMaterial = MeshComponent->CreateDynamicMaterialInstance(0);
		if (DynMaterial)
		{
			DynMaterial->SetVectorParameterValue("BaseColor", NewColor);
		}
	}
}