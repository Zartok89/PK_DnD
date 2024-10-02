// Fill out your copyright notice in the Description page of Project Settings.

#include "PKDNDTreeNode.h"

APKDNDTreeNode::APKDNDTreeNode()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

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
	for (APKDNDTreeNode* Child : mNodeChildren)
	{
		if (Child)
		{
			DrawDebugLine(GetWorld(), GetActorLocation(), Child->GetActorLocation(), FColor::Green, false, -1.f, 0, 5.f);
		}
	}
}

void APKDNDTreeNode::AddChild(APKDNDTreeNode* ChildNode)
{
	if (mNodeChildren.Num() < mMaxChildren && ChildNode)
	{
		mNodeChildren.Add(ChildNode);
	}
}

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