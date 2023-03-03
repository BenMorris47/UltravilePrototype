// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SomnusToolsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ULTRAVILE_ENGINE_API USomnusToolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#pragma region SortingFunctions

    UFUNCTION(BlueprintCallable, Category = "SomnusTools||Sorting Functions")            // Expose node to blueprints using 'BlueprintCallable', 'Category' gives your function a "searchable" header category in BPs
        static void  Integer_Sort(UPARAM(ref) TArray <int32>& Array_To_Sort, bool Descending, TArray <int32>& Sorted_Array);   // 'static' so node is accessible anywhere
                                                                                                                                // 'UPARAM' makes argument an exposed input pin
    UFUNCTION(BlueprintCallable, Category = "SomnusTools||Sorting Functions")                                                                //  'UPARAM(ref)' passes argument by reference
        static void  Float_Sort(UPARAM(ref) TArray <float>& Array_To_Sort, bool Descending, TArray <float>& Sorted_Array);

    UFUNCTION(BlueprintCallable, Category = "SomnusTools||Sorting Functions")
        static void  String_Sort(UPARAM(ref) TArray <FString>& Array_To_Sort, bool Descending, TArray <FString>& Sorted_Array);
#pragma endregion

#pragma region FileTools
    UFUNCTION(BlueprintPure, Category = "SomnusTools||File Tools")
        static FString  GetSavedDir();

    UFUNCTION(BlueprintPure, Category = "SomnusTools||File Tools")
        static FString GetContentDir();
#pragma endregion

UFUNCTION(BlueprintPure, meta = (DisplayName = "GetAppVersion"), Category = "Game Config")
static FString GetAppVersion();

};
