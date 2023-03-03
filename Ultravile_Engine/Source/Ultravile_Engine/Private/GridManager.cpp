// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManager.h"


// Sets default values
AGridManager::AGridManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGridManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//loop through all coordinates to spawn grid
void AGridManager::PopulateGridCells(int xSize, int ySize, int zSize, bool matchTerrain, bool checkPlayerFits,
                                     float playerHeight)
{
	for (int x = 0; x > xSize; x++)
	{
		for (int y = 0; y > ySize; y++)
		{
			for (int z = 0; z > zSize; z++)
			{
				FIntVector gridIndex = FIntVector(x,y,z);
				FVector gridCellLocation = FVector((x * CellSize)+(CellSize * 0.5f),(y * CellSize)+(CellSize * 0.5f),(z * CellSize)+(CellSize * 0.5f));
				
			}
		}
	}
}
