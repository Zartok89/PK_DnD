// Fill out your copyright notice in the Description page of Project Settings.


#include "PKDnDNodeObject.h"

UPKDnDNodeObject* UPKDnDNodeObject::Node(FString Data)
{
	mData = Data;
	return this;
}
