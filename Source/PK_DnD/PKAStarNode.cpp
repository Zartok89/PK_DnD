// Fill out your copyright notice in the Description page of Project Settings.

#include "PKAStarNode.h"

UPKAStarNode::UPKAStarNode()
{
	GCost = 0.0f;
	HCost = 0.0f;
	Parent = nullptr;
	bIsWalkable = true;
}