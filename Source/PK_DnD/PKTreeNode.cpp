#include "PKTreeNode.h"

APKTreeNode::APKTreeNode()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	mData = 0;
	mMaxChildren = 2;
}

void APKTreeNode::BeginPlay()
{
	Super::BeginPlay();
}

void APKTreeNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (APKTreeNode* Child : mChildren)
	{
		if (Child)
		{
			DrawDebugLine(
				GetWorld(),
				GetActorLocation(),
				Child->GetActorLocation(),
				FColor::Green,
				false,
				0.5f,
				0,
				5.f);
		}
	}
}

void APKTreeNode::AddChild(APKTreeNode* ChildNode)
{
	if (mChildren.Num() < mMaxChildren && ChildNode)
	{
		mChildren.Add(ChildNode);
	}
}