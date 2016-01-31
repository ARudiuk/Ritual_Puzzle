// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Amazon_Levels.generated.h"

/**
 * 
 */
UCLASS()
class RITUAL_PUZZLE_API UAmazon_Levels : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintCallable, Category = "AlexSucks")
		static TArray<int> GetAmazonLevel(int level_number, int &n_count);
	
		UFUNCTION(BlueprintCallable, Category = "AlexSucks")
		static TArray<int> GetAmazonMoves(TArray <int> Grid, int dim);
	
};
