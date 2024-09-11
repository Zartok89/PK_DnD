// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PKDnDNodeObject.generated.h"

/**
 * 
 */
UCLASS()
class PK_DND_API UPKDnDNodeObject : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category="NodeObject")
	UPKDnDNodeObject* Node (FString Data);

	/*
	* Variables
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NodeObject")
	FString mData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NodeObject")
	TObjectPtr<UPKDnDNodeObject> NextNode;

};
