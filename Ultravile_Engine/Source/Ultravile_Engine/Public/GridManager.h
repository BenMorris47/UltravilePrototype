// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathFinder.h"
#include "GridManager.generated.h"


UCLASS()
class ULTRAVILE_ENGINE_API AGridManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UPathFinder* pathFinder;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float CellSize = 100;

	UFUNCTION(BlueprintCallable)
	void PopulateGridCells(int xSize, int ySize, int zSize, bool matchTerrain, bool checkPlayerFits, float playerHeight);
};
