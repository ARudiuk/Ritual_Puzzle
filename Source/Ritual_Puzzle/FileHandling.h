// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileHandling.generated.h"

/**
 * 
 */
UCLASS()
class RITUAL_PUZZLE_API UFileHandling : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "FileHandlingLibrary")
	static TArray<int> ReadAmazonLevel(FString path, int &n_count);
	
};
