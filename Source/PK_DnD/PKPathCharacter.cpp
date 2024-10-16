// Fill out your copyright notice in the Description page of Project Settings.

#include "PKPathCharacter.h"
#include "PKGraphNode.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APKPathCharacter::APKPathCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementSpeed = 300.0f;
	CurrentNodeIndex = 0;
	bIsMoving = false;

	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
}

// Called when the game starts or when spawned
void APKPathCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APKPathCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving && PathNodes.Num() > 0 && CurrentNodeIndex < PathNodes.Num())
	{
		FVector TargetLocation = PathNodes[CurrentNodeIndex]->GetActorLocation();
		FVector Direction = (TargetLocation - GetActorLocation()).GetSafeNormal();
		FVector NewLocation = GetActorLocation() + Direction * MovementSpeed * DeltaTime;

		SetActorLocation(NewLocation);

		if (FVector::Dist(GetActorLocation(), TargetLocation) < 10.0f)
		{
			CurrentNodeIndex++;

			if (CurrentNodeIndex >= PathNodes.Num())
			{
				bIsMoving = false;
			}
		}
	}
}

void APKPathCharacter::SetPath(const TArray<APKGraphNode*>& NewPath)
{
	PathNodes = NewPath;
	CurrentNodeIndex = 0;
}

void APKPathCharacter::StartMoving()
{
	bIsMoving = true;
}