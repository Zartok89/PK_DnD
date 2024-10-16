// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PKPathCharacter.generated.h"

class APKGraphNode;

UCLASS()
class PK_DND_API APKPathCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APKPathCharacter();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetPath(const TArray<APKGraphNode*>& NewPath);

	UFUNCTION(BlueprintCallable)
	void StartMoving();

	/*
	 * Variables
	 */
	UPROPERTY()
	TArray<APKGraphNode*> PathNodes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PathCharacter")
	float MovementSpeed;

	UPROPERTY(VisibleAnywhere, Category = "PathCharacter")
	int32 CurrentNodeIndex;

	UPROPERTY(VisibleAnywhere, Category = "PathCharacter")
	bool bIsMoving;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
