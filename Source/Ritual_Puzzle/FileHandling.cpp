// Fill out your copyright notice in the Description page of Project Settings.

#include "Ritual_Puzzle.h"
#include "FileHandling.h"
#include <iostream>
#include <fstream>

using std::cout;

TArray<int> UFileHandling::ReadAmazonLevel(FString path, int &n_count)
{
	std::ifstream fin;
	fin.open(*path, std::ios::in);
	char ch;
//#if UE_BUILD_DEBUG
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, strerror(errno));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, *path);
//#endif
//This gets n for nxn matrix size
	fin.get(ch);

	n_count = (int)ch;
	char* chs = new char[n_count*n_count];
	fin.get(chs, n_count*n_count);
	//Possible memory leak heeere
	TArray<int> values;
	values.Init(-1, n_count*n_count);
	for (int i = 0;i < n_count*n_count;i++)
	{
		values[i] = (int)chs[i];
	}
	delete chs;
	return values; 
}

