// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonTools.generated.h"


class FJsonObject;

UCLASS()
class ULTRAVILE_ENGINE_API UJsonTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

/*-------------------------------------EXAMPLE FUNCTIONS FOR USE--------------------------------
 *public:
	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 * @return 
	 #1#
	UFUNCTION(BlueprintCallable, Category = "Json Tools")
	static  UStruct* ReadStructFromJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage);

	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param dataStruct The struct you want to write to the file
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 #1#
	UFUNCTION(BlueprintCallable, Category = "Json Tools")
	static  void WriteStructToJson(FString jsonFilePath, UStruct* dataStruct, bool& outSuccess, FString& outInfoMessage);
	*/
	
public:
	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 * @return 
	 */
	static  TSharedPtr<FJsonObject> ReadJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage);
	/**
	 * @brief 
	 * @param jsonFilePath The path for the file to read
	 * @param jsonObject The Json object you want to write to the file
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage more info about action results
	 */
	static  void WriteJson(FString jsonFilePath, TSharedPtr<FJsonObject> jsonObject, bool& outSuccess, FString& outInfoMessage);
};
