// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonTools.h"

#include "JsonObjectConverter.h"
#include "TextFileTools.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

/* -------------------------------------EXAMPLE FUNCTIONS FOR USE--------------------------------
 *
 *StructType UJsonTools::ReadStructFromJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage)
{
	//try read file
	TSharedPtr<FJsonObject> jsonObject = ReadJson(jsonFilePath, outSuccess, outInfoMessage);
	if (!outSuccess)
	{
		return StructType();
	}

	StructType retStruct;
	//try convert jsonObject to struct
	if (!FJsonObjectConverter::JsonObjectToUStruct<StructType>(jsonObject.ToSharedRef(),&retStruct))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read Struct from Json file failed - Was not able to Convert Json Object to Struct. Is it the correct format? - '%s'"),*jsonFilePath);
		return StructType();
	}
	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Read Struct from Json file Successful - '%s'"),*jsonFilePath);
	return retStruct;
}

void UJsonTools::WriteStructToJson(FString jsonFilePath, StructType dataStruct, bool& outSuccess, FString& outInfoMessage)
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
	WriteJson(jsonFilePath, jsonObject, outSuccess, outInfoMessage);
}

*/

TSharedPtr<FJsonObject> UJsonTools::ReadJson(FString jsonFilePath, bool& outSuccess, FString& outInfoMessage)
{
	//try to read file
	FString JsonString = UTextFileTools::ReadStringFromTextFile(jsonFilePath,outSuccess,outInfoMessage);
	if (!outSuccess)
	{
		return nullptr;
	}

	TSharedPtr<FJsonObject> retJsonObject;

	//try to convert string to json object. output to retJsonObject
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(JsonString),retJsonObject))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read Json file failed - Was not able to Deserialize Json String. Is it the correct format? - '%s'"),*jsonFilePath);
		return nullptr;
	}

	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Read Json file Successful - '%s'"),*jsonFilePath);
	return retJsonObject; //return jsonobject
}

void UJsonTools::WriteJson(FString jsonFilePath, TSharedPtr<FJsonObject> jsonObject, bool& outSuccess, FString& outInfoMessage)
{
	FString JsonString;

	//attempts to serialize thejsonobject
	if (!FJsonSerializer::Serialize(jsonObject.ToSharedRef(),TJsonWriterFactory<>::Create(&JsonString, 0)))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Write Json file failed - Was not able to Serialize Json Object. Is Json Object Valid? - '%s'"),*jsonFilePath);
		return;
	}

	//attempt to write json object string to text file
	UTextFileTools::WriteStringToTextFile(jsonFilePath, JsonString, outSuccess,outInfoMessage);
	if (!outSuccess)
	{
		return;
	}
	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Write Json file Successful - '%s'"),*jsonFilePath);
}
