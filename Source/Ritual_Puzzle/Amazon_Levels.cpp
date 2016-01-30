// Fill out your copyright notice in the Description page of Project Settings.

#include "Ritual_Puzzle.h"
#include "Amazon_Levels.h"


TArray<int> UAmazon_Levels::GetAmazonLevel(int level_number, int &n_count)
{
	TArray<int32> table;	
	switch (level_number)
	{
	case 0:
		int32 tableinit[]= {0, 0, 0, 0,
							1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 0, 1};
		table.Append(tableinit, ARRAY_COUNT(tableinit));
		n_count = 4;
	}	
	return table;
}

