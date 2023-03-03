// Fill out your copyright notice in the Description page of Project Settings.


#include "CardManager.h"
#include "JsonTools.h"
#include "JsonObjectConverter.h"

// Sets default values
ACardManager::ACardManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACardManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FCardDictionaryStruct ACardManager::ReadCardStructFromJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage)
{
	//try read file
	TSharedPtr<FJsonObject> jsonObject = UJsonTools::ReadJson(jsonFilePath, outSuccess, outInfoMessage);
	if (!outSuccess)
	{
		return FCardDictionaryStruct();
	}

	FCardDictionaryStruct retStruct;
	//try convert jsonObject to struct
	if (!FJsonObjectConverter::JsonObjectToUStruct<FCardDictionaryStruct>(jsonObject.ToSharedRef(),&retStruct))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read Struct from Json file failed - Was not able to Convert Json Object to Struct. Is it the correct format? - '%s'"),*jsonFilePath);
		return FCardDictionaryStruct();
	}
	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Read Struct from Json file Successful - '%s'"),*jsonFilePath);
	return retStruct;
}

void ACardManager::WriteCardStructToJson(FString jsonFilePath, FCardDictionaryStruct dataStruct, bool& outSuccess, FString& outInfoMessage)
{
	//Try convert struct to json object
	TSharedPtr<FJsonObject> jsonObject = FJsonObjectConverter::UStructToJsonObject(dataStruct);
	if (jsonObject == nullptr)
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Write Struct to Json file failed - Was not able to Convert Struct to Json Object. Is it the correct format? - '%s'"),*jsonFilePath);
		return;
	}

	//try to write json file
	UJsonTools::WriteJson(jsonFilePath, jsonObject, outSuccess, outInfoMessage);
}


