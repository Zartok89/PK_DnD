// Fill out your copyright notice in the Description page of Project Settings.

#include "PKDNDTreeManager.h"
#include "PKDNDTreeNode.h"

APKDNDTreeManager::APKDNDTreeManager()
{
	PrimaryActorTick.bCanEverTick = true;
	mMaxDepth = 3;
	mObjectSpacing = 200.f;
	ColorDelayInterval = 0.5f;
	BreadthSearchColor = FLinearColor::Red;
	DepthSearchColor = FLinearColor::Blue;
}

void APKDNDTreeManager::BeginPlay()
{
	Super::BeginPlay();

	BuildTree();
}

void APKDNDTreeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APKDNDTreeManager::BuildTree()
{
	FActorSpawnParameters SpawnParams;
	mRootNode = GetWorld()->SpawnActor<APKDNDTreeNode>(NodeObject, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);
	mRootNode->mData = 1;

	CreateChildren(mRootNode, 1, mMaxDepth);
}

void APKDNDTreeManager::CreateChildren(APKDNDTreeNode* ParentNode, int32 CurrentDepth, int32 MaxDepth)
{
	if (CurrentDepth >= MaxDepth)
	{
		return;
	}

	int32 AmountOfChildren = ParentNode->mMaxChildren;

	float Radius = FMath::Max(mObjectSpacing, mObjectSpacing * (MaxDepth - CurrentDepth));

	for (int32 i = 0; i < AmountOfChildren; ++i)
	{
		float Angle = (360.f / AmountOfChildren) * i;
		float Rad = FMath::DegreesToRadians(Angle);

		FVector Offset(FMath::Cos(Rad) * Radius, FMath::Sin(Rad) * Radius, -mObjectSpacing * CurrentDepth);
		FVector ChildLocation = ParentNode->GetActorLocation() + Offset;

		FActorSpawnParameters SpawnParams;
		APKDNDTreeNode* ChildNode = GetWorld()->SpawnActor<APKDNDTreeNode>(NodeObject, ChildLocation, FRotator::ZeroRotator, SpawnParams);
		ChildNode->mData = ParentNode->mData * 10 + i + 1;
		ChildNode->mMaxChildren = ParentNode->mMaxChildren;

		ParentNode->AddChild(ChildNode);

		CreateChildren(ChildNode, CurrentDepth + 1, MaxDepth);
	}
}

void APKDNDTreeManager::DepthFirstTraversal()
{
	if (mRootNode)
	{
		TArray<APKDNDTreeNode*> TraversalNodes;
		DepthFirstTraversalHelper(mRootNode, TraversalNodes);
		StartColorChangeSequence(TraversalNodes, DepthSearchColor);
	}
}

void APKDNDTreeManager::BreadthFirstTraversal()
{
    if (!mRootNode)  
    {  
        return;  
    }  

    TQueue<APKDNDTreeNode*> NodeQueue;  
    TArray<APKDNDTreeNode*> TraversalNodes;  

    NodeQueue.Enqueue(mRootNode);  

    while (!NodeQueue.IsEmpty())  
    {  
        APKDNDTreeNode* CurrentNode;  
        NodeQueue.Dequeue(CurrentNode);  

        if (CurrentNode)  
        {  
            TraversalNodes.Add(CurrentNode);  

            for (APKDNDTreeNode* Child : CurrentNode->mNodeChildren)  
            {  
                NodeQueue.Enqueue(Child);  
            }  
        }  
    }  

    StartColorChangeSequence(TraversalNodes, BreadthSearchColor);  
}

void APKDNDTreeManager::DepthFirstTraversalHelper(APKDNDTreeNode* Node, TArray<APKDNDTreeNode*>& TraversalNodes)
{
	if (!Node)
	{
		return;
	}

	TraversalNodes.Add(Node);

	UE_LOG(LogTemp, Log, TEXT("Visited Node with Data: %d"), Node->mData);

	for (APKDNDTreeNode* Child : Node->mNodeChildren)
	{
		DepthFirstTraversalHelper(Child, TraversalNodes);
	}
}

void APKDNDTreeManager::StartColorChangeSequence(const TArray<APKDNDTreeNode*>& Nodes, FLinearColor Color)
{
    for (int32 Index = 0; Index < Nodes.Num(); ++Index)  
    {  
        float Delay = Index * ColorDelayInterval;  
        FTimerHandle TimerHandle;  
        FTimerDelegate TimerDelegate;  

        APKDNDTreeNode* NodeToColor = Nodes[Index];  

        TimerDelegate.BindLambda([NodeToColor, Color]()  
        {  
            if (NodeToColor)  
            {  
                NodeToColor->SetNodeColor(Color);  
            }  
        });  

        GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, Delay, false);  
    }  
}