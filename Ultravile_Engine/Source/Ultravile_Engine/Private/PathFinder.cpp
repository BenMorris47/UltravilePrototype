// Fill out your copyright notice in the Description page of Project Settings.


#include "PathFinder.h"
#include "GridCell.h"
#include "Algo/Reverse.h"

TArray<FIntVector> UPathFinder::DijkstraPathing(UPARAM()FIntVector startingCell, UPARAM()FIntVector finishingCell, UPARAM() int range, UPARAM(ref)TMap<FIntVector, UGridCell*> gridIndexMap, UPARAM() bool onlyWalkable)
{
	TArray<FFloodFillStruct> frontier;
	TMap<FIntVector,FFloodFillStruct> visitedCells;
	
	//Set up first frontier.
	for (int i = 0; i < gridIndexMap[startingCell]->neighbouringCells.Num(); i++)
	{
		if (visitedCells.Contains(gridIndexMap[startingCell]->neighbouringCells[i])|| !(*gridIndexMap.Find(gridIndexMap[startingCell]->neighbouringCells[i]))->isWalkable && onlyWalkable)
		{
			continue;
		}
		frontier.Add(FFloodFillStruct(startingCell, gridIndexMap[startingCell]->neighbouringCells[i], (*gridIndexMap.Find(gridIndexMap[startingCell]->neighbouringCells[i]))->additionalPathCost));
	}
	visitedCells.Add(startingCell, FFloodFillStruct(FIntVector(0, 0, 0), startingCell, 0));

	FFloodFillStruct selectedFrontierStruct = visitedCells[startingCell];
	while (frontier.Num() > 0 && startingCell != finishingCell) //Run through frontier until empty.
	{
		//Get the current FFloodFillStruct we are working on
		FFloodFillStruct currentFrontierStruct;
		currentFrontierStruct = *frontier.GetData();

		selectedFrontierStruct = currentFrontierStruct;
		UGridCell* currentFrontierCell = *gridIndexMap.Find(currentFrontierStruct.currentIndex);
		if ((*currentFrontierCell).cellIndex == finishingCell )
		{
			break;
		}
		for (int i = 0; i < currentFrontierCell->neighbouringCells.Num(); i++)
		{
			//THIS TOOK 2DAYS I WANT TO DIE BUT IT FINALLY WORKS ;n;
			if (visitedCells.Contains((*currentFrontierCell).neighbouringCells[i]) || (currentFrontierStruct).combinedCost + (*currentFrontierCell).additionalPathCost > range || !(*gridIndexMap.Find(currentFrontierCell->neighbouringCells[i]))->isWalkable && onlyWalkable)
			{
				continue;
			}
			frontier.Add(FFloodFillStruct(currentFrontierStruct.currentIndex, (*currentFrontierCell).neighbouringCells[i], currentFrontierStruct.combinedCost + (*currentFrontierCell).additionalPathCost));
		}
		visitedCells.Add((*currentFrontierCell).cellIndex,currentFrontierStruct);
		frontier.RemoveAt(0);
	}

	TArray<FIntVector> vectorPath;
	while (selectedFrontierStruct.currentIndex != startingCell)
	{
		vectorPath.Add(selectedFrontierStruct.currentIndex);
		selectedFrontierStruct =visitedCells[selectedFrontierStruct.parentIndex];
		//Somthing
	}
	vectorPath.Add(startingCell);
	Algo::Reverse(vectorPath);
	return vectorPath;
}

TArray<FIntVector> UPathFinder::DijkstraPathingFloodFill(UPARAM()FIntVector startingCell, UPARAM() int range, UPARAM(ref)TMap<FIntVector, UGridCell*> gridIndexMap, UPARAM() bool onlyWalkable, TMap<FIntVector,FFloodFillStruct>& visitedMap)
{
	TArray<FFloodFillStruct> frontier;
	TMap<FIntVector,FFloodFillStruct> visitedCells;
	
	
	for (int i = 0; i < gridIndexMap[startingCell]->neighbouringCells.Num(); i++)
	{
		if (visitedCells.Contains(gridIndexMap[startingCell]->neighbouringCells[i])|| !(*gridIndexMap.Find(gridIndexMap[startingCell]->neighbouringCells[i]))->isWalkable && onlyWalkable)
		{
			continue;
		}
		frontier.Add(FFloodFillStruct(startingCell, gridIndexMap[startingCell]->neighbouringCells[i], (*gridIndexMap.Find(gridIndexMap[startingCell]->neighbouringCells[i]))->additionalPathCost));
	}
	visitedCells.Add(startingCell, FFloodFillStruct(FIntVector(0, 0, 0), startingCell, 0));
	

	FFloodFillStruct selectedFrontierStruct = visitedCells[startingCell];
	while (frontier.Num() > 0 )
	{
		//Get the current FFloodFillStruct we are working on
		FFloodFillStruct currentFrontierStruct;
		currentFrontierStruct = *frontier.GetData();

		selectedFrontierStruct = currentFrontierStruct;
		UGridCell* currentFrontierCell = *gridIndexMap.Find(currentFrontierStruct.currentIndex);
		for (int i = 0; i < currentFrontierCell->neighbouringCells.Num(); i++)
		{
			//THIS TOOK 2DAYS I WANT TO DIE BUT IT FINALLY WORKS ;n;
			if (visitedCells.Contains((*currentFrontierCell).neighbouringCells[i]) || currentFrontierStruct.combinedCost + (*currentFrontierCell).additionalPathCost > range || !(*gridIndexMap.Find(currentFrontierCell->neighbouringCells[i]))->isWalkable && onlyWalkable)
			{
				continue;
			}
			frontier.Add(FFloodFillStruct(currentFrontierStruct.currentIndex, (*currentFrontierCell).neighbouringCells[i], currentFrontierStruct.combinedCost + (*currentFrontierCell).additionalPathCost));
		}
		visitedCells.Add((*currentFrontierCell).cellIndex,currentFrontierStruct);
		frontier.RemoveAt(0);
	}

	TArray<FIntVector> vectorPath;
	while (selectedFrontierStruct.currentIndex != startingCell)
	{
		vectorPath.Add(selectedFrontierStruct.currentIndex);
		selectedFrontierStruct =visitedCells[selectedFrontierStruct.parentIndex];
		//Somthing
	}
	vectorPath.Add(startingCell);
	Algo::Reverse(vectorPath);
	visitedMap = visitedCells;
	return vectorPath;
}
