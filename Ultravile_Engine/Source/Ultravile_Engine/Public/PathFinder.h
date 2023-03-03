// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridCell.h"
#include "PathFinder.generated.h"


USTRUCT(BlueprintType)
struct FFloodFillStruct //struct to store information on costs
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FIntVector parentIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FIntVector currentIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int combinedCost;
	//constructors
	FFloodFillStruct()
	{
		this->combinedCost = 0;
	}
	FFloodFillStruct(FIntVector parentIndex,FIntVector currentIndex,int combinedCost)
	{
		this->combinedCost = combinedCost;
		this->currentIndex = currentIndex;
		this->parentIndex = parentIndex;
	}

	//operator override
	FORCEINLINE bool operator==(const FFloodFillStruct& otherItem) const
	{
		return currentIndex.X == otherItem.currentIndex.X && currentIndex.Y == otherItem.currentIndex.Y && currentIndex.Z == otherItem.currentIndex.Z;
	}
};

/**
 * 
 */
UCLASS(BlueprintType)
class ULTRAVILE_ENGINE_API UPathFinder : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)//DijkstraPathing but its actually just a generic flood fill that loops round the frontier regardless of costs
		TArray<FIntVector> DijkstraPathing(UPARAM()FIntVector startingCell, UPARAM()FIntVector finishingCell, UPARAM()int range, UPARAM(ref)TMap<FIntVector, UGridCell*> gridIndexMap, UPARAM() bool onlyWalkable);

	UFUNCTION(BlueprintCallable)//DijkstraPathing but its actually takes in the costs costs
		TArray<FIntVector> DijkstraPathingFloodFill(UPARAM()FIntVector startingCell, UPARAM() int range, UPARAM(ref)TMap<FIntVector, UGridCell*> gridIndexMap, UPARAM() bool onlyWalkable, TMap<FIntVector,FFloodFillStruct>& visitedMap);
};
