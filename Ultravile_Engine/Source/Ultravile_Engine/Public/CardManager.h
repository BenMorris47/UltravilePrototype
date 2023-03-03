// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardManager.generated.h"


UENUM(BlueprintType)
enum ECardTargetType 
{
	FriendlyUnit UMETA(DisplayName = "FriendlyUnit"),
	EnemyUnit   UMETA(DisplayName = "EnemyUnit"),
	AllUnits      UMETA(DisplayName = "AllUnits"),
	EmptyCell   UMETA(DisplayName = "EmptyCell"),
	AllCells   UMETA(DisplayName = "AllCells")
};

USTRUCT(BlueprintType)
struct FCardData //all data for cards
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString cardName = "Unassigned Name";
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString cardDescription = "Unassigned Description";
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString cardImageFileName = "cardPlaceholder.png";
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> particleNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int pipCost = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int castRange = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool removeOnUse = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> cardSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool orientFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int cardDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TEnumAsByte<ECardTargetType> targetType;
	
};

USTRUCT(BlueprintType)
struct FCardDictionaryStruct //Struct to hold data dictionary (allows multiple dictionaries to be stored in array)
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FString, FCardData> cardDataDic;
};

UCLASS()
class ULTRAVILE_ENGINE_API ACardManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACardManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "Card Manager")
	static  FCardDictionaryStruct ReadCardStructFromJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage);

	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param dataStruct The struct you want to write to the file
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 */
	UFUNCTION(BlueprintCallable, Category = "Card Manager")
	static  void WriteCardStructToJson(FString jsonFilePath, FCardDictionaryStruct dataStruct, bool& outSuccess, FString& outInfoMessage);
	
};

