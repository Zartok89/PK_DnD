// Fill out your copyright notice in the Description page of Project Settings.

#include "PKDnDInsertionSort.h"

void UPKDnDInsertionSort::AddNumber(int32 NewNumber)
{
	Array.Emplace(NewNumber);
}

void UPKDnDInsertionSort::PrintArray()
{
	if (!Array.IsEmpty())
	{
		int Index = 0;
		for (auto& Elements : Array)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Index: %d | Value: %d"), Index, Elements));
			Index++;
		}
	}
}

void UPKDnDInsertionSort::InsertionSortAlgorithm()
{
	int32 TempIndex = 0;

	for (int32 i = 1; i <= Array.Num(); i++)
	{
		TempIndex = Array.Num() - 1;

		while (TempIndex > 0)
		{
			if (Array[TempIndex] < Array[TempIndex - 1])
			{
				Array.Swap(TempIndex, TempIndex - 1);
				TempIndex--;
			}
			TempIndex--;
		}
	}
}