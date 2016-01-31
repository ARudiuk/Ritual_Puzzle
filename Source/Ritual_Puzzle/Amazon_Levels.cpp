// Fill out your copyright notice in the Description page of Project Settings.

#include "Ritual_Puzzle.h"
#include "Amazon_Levels.h"
#include <algorithm>


TArray<int> UAmazon_Levels::GetAmazonLevel(int level_number, int &n_count)
{
	TArray<int32> table;
	switch (level_number)
	{
	case 0:
		int32 tableinit[] = { 0, 0, 0, 1,
							0, 0, 2, 0,
							0, 1, 0, 0,
							0, 0, 0, 0 };
		table.Append(tableinit, ARRAY_COUNT(tableinit));
		n_count = 4;
	}
	return table;
}

TArray<int> UAmazon_Levels::GetAmazonMoves(TArray<int> Grid, int dim, int pawn_index)
{
	int congru, value_x, value_y, reachable_tile;
	TArray<int> Moves;

	int i = pawn_index;
	if (dim == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString("Dimension was 0"));
		return Moves;
	}
	value_x = i%dim;
	congru = i - value_x;
	if (i - dim*value_x == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString("i - dim*value_x was 0"));
		return Moves;
	}
	value_y = congru / (dim);
			

	for (int alpha = 0; alpha <= dim - 1; alpha++)
	{
		reachable_tile = congru + alpha;
		Moves.Add(reachable_tile);
	}
			
	for (int k = -value_y; k <= dim - 1 - value_y; k++)
	{
		reachable_tile = i + k*dim;
		Moves.Add(reachable_tile);
	}
			
	for (int beta_one = 0; beta_one <= std::min(value_x,value_y); beta_one++)
	{
		reachable_tile = i - beta_one*(1 + dim);
		Moves.Add(reachable_tile);
	}

	for (int beta_two = 0; beta_two <= std::min(dim-1-value_x,value_y); beta_two++)
	{
		reachable_tile = i + beta_two*(1 - dim);
		Moves.Add(reachable_tile);
	}

	for (int beta_three = 0; beta_three <= std::min(dim - 1 - value_x, dim-1-value_y); beta_three++)
	{
		reachable_tile = i + beta_three*(1 + dim);
		Moves.Add(reachable_tile);
	}

	for (int beta_four = 0; beta_four <= std::min(value_x, dim-1-value_y); beta_four++)
	{
		reachable_tile = i - beta_four*(1 - dim);
		Moves.Add(reachable_tile);
	}
	return Moves;

}