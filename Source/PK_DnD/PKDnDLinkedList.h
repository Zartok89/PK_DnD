// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PKDnDLinkedList.generated.h"

class UPKDnDNodeObject;

UCLASS(BlueprintType, Blueprintable)
class PK_DND_API UPKDnDLinkedList : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category="LinkedList")
	void Append(FString Data);

	UFUNCTION(BlueprintCallable, Category="LinkedList")
	void Prepend(FString Data);

	UFUNCTION(BlueprintCallable, Category="LinkedList")
	void DeleteWithValue(FString Data);

	UFUNCTION(BlueprintCallable, Category="LinkedList")
	void PrintList();

	/*
	* Variables
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="LinkedList")
	TObjectPtr<UPKDnDNodeObject> Head;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="LinkedList")
	FString mData;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="LinkedList")
	TObjectPtr<UPKDnDNodeObject> CurrentNode;


};
