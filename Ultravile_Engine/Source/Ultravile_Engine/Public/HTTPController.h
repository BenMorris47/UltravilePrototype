// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "http.h"
#include "HTTPController.generated.h"

/**
 * 
 */
UCLASS()
class ULTRAVILE_ENGINE_API UHTTPController : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//POSTs a URL
	 UFUNCTION(BlueprintCallable, Category = "HTTP||Request")
            static void  CallHTML(FString url, bool& Sucess);

	
};
