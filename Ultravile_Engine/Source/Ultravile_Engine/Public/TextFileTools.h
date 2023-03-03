// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextFileTools.generated.h"

/**
 * 
 */
UCLASS()
class ULTRAVILE_ENGINE_API UTextFileTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * @brief 
	 * @param filePath Path of the file to read
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage More info about action
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "Text Tools")
	static FString ReadStringFromTextFile(FString filePath, bool& outSuccess, FString& outInfoMessage);
	/**
	 * @brief 
	 * @param filePath Path of the file to read
	 * @param string string to write to file
	 * @param outSuccess was the file read successfully
	 * @param outInfoMessage More info about action
	 * @return 
	 */
	UFUNCTION(BlueprintCallable, Category = "Text Tools")
	static void WriteStringToTextFile(FString filePath, FString string, bool& outSuccess, FString& outInfoMessage);
};
