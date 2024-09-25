// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PKDnDInsertionSort.generated.h"

/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class PK_DND_API UPKDnDInsertionSort : public UObject
{
	GENERATED_BODY()

public:

	/*
	* Functions
	*/
	UFUNCTION(BlueprintCallable, Category = "InsertionSort")
	void AddNumber(int32 NewNumber);

	UFUNCTION(BlueprintCallable, Category = "InsertionSort")
	void PrintArray();

	UFUNCTION(BlueprintCallable, Category = "InsertionSort")
	void InsertionSortAlgorithm();

	/*
	* Variables
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InsertionSort")
	TArray<int32> Array;

};
