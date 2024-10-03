#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKTreeNode.generated.h"

UCLASS()
class PK_DND_API APKTreeNode : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APKTreeNode();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "TreeNode")
	void AddChild(APKTreeNode* ChildNode);

	/*
	 * Variables
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	int32 mData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	int32 mMaxChildren;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	TArray<APKTreeNode*> mChildren;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeNode")
	UStaticMeshComponent* MeshComponent;

};
