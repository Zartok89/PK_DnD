#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PKTreeManager.generated.h"

class APKTreeNode;

UCLASS()
class PK_DND_API APKTreeManager : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APKTreeManager();

	virtual void Tick(float DeltaTime) override;

	/*
	* Functions
	*/
	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void BuildTree();

	UFUNCTION(BlueprintCallable, Category = "TreeManager")
	void CreateChildren(APKTreeNode* ParentNode, int32 CurrentDepth, int32 MaxDepth);

	/*
	 * Variables
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	APKTreeNode* mRootNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	int32 mMaxDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	float mObjectSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TreeManager")
	TSubclassOf<AActor> NodeObject;
};
