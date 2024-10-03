#include "PKTreeManager.h"
#include "PKTreeNode.h"

APKTreeManager::APKTreeManager()
{
	PrimaryActorTick.bCanEverTick = true;
	mMaxDepth = 3;
	mObjectSpacing = 200.f;
}

void APKTreeManager::BeginPlay()
{
	Super::BeginPlay();

	BuildTree();
}

void APKTreeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APKTreeManager::BuildTree()
{
	FActorSpawnParameters SpawnParams;
	mRootNode = GetWorld()->SpawnActor<APKTreeNode>(NodeObject, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);

	mRootNode->mData = 1;

	CreateChildren(mRootNode, 1, mMaxDepth);
}

void APKTreeManager::CreateChildren(APKTreeNode* ParentNode, int32 CurrentDepth, int32 MaxDepth)
{
	if (CurrentDepth >= MaxDepth)
	{
		return;
	}

	int32 AmountOfChildren = ParentNode->mMaxChildren;

	float Radius = FMath::Max(mObjectSpacing, mObjectSpacing * (MaxDepth - CurrentDepth));

	for (int32 i = 0; i < AmountOfChildren; ++i)
	{
		// ---- Extra stuff for spawning and position in Unreal ----
		float Angle = (360.f / AmountOfChildren) * i;
		float Rad = FMath::DegreesToRadians(Angle);

		FVector Offset(FMath::Cos(Rad) * Radius, FMath::Sin(Rad) * Radius, -mObjectSpacing * CurrentDepth);
		FVector ChildLocation = ParentNode->GetActorLocation() + Offset;

		FActorSpawnParameters SpawnParams;
		APKTreeNode* ChildNode = GetWorld()->SpawnActor<APKTreeNode>(NodeObject, ChildLocation, FRotator::ZeroRotator, SpawnParams);
		// ----------------------------------------------------

		ChildNode->mData = ParentNode->mData * 10 + i + 1;
		ChildNode->mMaxChildren = ParentNode->mMaxChildren;

		ParentNode->AddChild(ChildNode);

		CreateChildren(ChildNode, CurrentDepth + 1, MaxDepth);
	}
}