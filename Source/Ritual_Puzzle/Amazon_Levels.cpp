// Fill out your copyright notice in the Description page of Project Settings.

#include "Ritual_Puzzle.h"
#include "Amazon_Levels.h"


TArray<int> UAmazon_Levels::GetAmazonLevel(int level_number, int &n_count)
{
	TArray<int32> table;	
	switch (level_number)
	{
	case 0:
		int32 tableinit[]= { 2, 0, 0, 0, 0};
		table.Append(tableinit, ARRAY_COUNT(tableinit));
		n_count = table[0];
	}	
	return table;
}

