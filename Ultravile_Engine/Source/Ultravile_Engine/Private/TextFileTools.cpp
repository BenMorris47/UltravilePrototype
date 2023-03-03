// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileTools.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

FString UTextFileTools::ReadStringFromTextFile(FString filePath, bool& outSuccess, FString& outInfoMessage)
{
	//check file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read string from file failed - File doesn't exist - '%s'"),*filePath);
		return "";
	}

	FString retString = "";

	//attempt to read file
	if (!FFileHelper::LoadFileToString(retString,*filePath))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read string from file failed - Was not able to read file. Was it a text file? - '%s'"),*filePath);
		return "";
	}
	
	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Read string from file Successful - '%s'"),*filePath);
	return retString; //return the string
}

void UTextFileTools::WriteStringToTextFile(FString filePath, FString string, bool& outSuccess, FString& outInfoMessage)
{
	//attempt to save the file
	if (!FFileHelper::SaveStringToFile(string,*filePath))
	{
		outSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Write string to file failed - Was not able to write file. Is path valid? Is file ReadOnly? - '%s'"),*filePath);
		return;
	}
	outSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Write string to file Successful - '%s'"),*filePath);
}
