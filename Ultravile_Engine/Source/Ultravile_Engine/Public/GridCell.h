// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridCell.generated.h"



/**
 * 
 */
UCLASS(Blueprintable)
class ULTRAVILE_ENGINE_API UGridCell : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CellInfo")
	TArray<FIntVector> neighbouringCells;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CellInfo")
	TArray<UGridCell*> neighbouringGridCells;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CellInfo")
	bool isWalkable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PathFinding")
	int additionalPathCost = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PathFinding")
	FIntVector cellIndex;

	

};
