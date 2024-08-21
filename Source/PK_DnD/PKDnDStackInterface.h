#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PKDnDStackInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPKDnDStackInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class PK_DND_API IPKDnDStackInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//FString versions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	void Push(const FString& Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	FString Pop();

	//int32 versions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	void IntPush(const int32 Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	int32 IntPop();
};