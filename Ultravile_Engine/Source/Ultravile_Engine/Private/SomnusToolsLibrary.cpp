// Fill out your copyright notice in the Description page of Project Settings.


#include "SomnusToolsLibrary.h"
#include "CoreMinimal.h"



//==================================== Sorting Functions ====================================

void USomnusToolsLibrary::Integer_Sort(UPARAM(ref) TArray <int32>& Array_To_Sort, bool Descending, TArray <int32>& Sorted_Array)
{
    int32 m = Array_To_Sort.Num();          // Return the array size 
    int32 a, k;
    bool bDidSwap;

    for (a = 0; a < (m - 1); a++)
    {
        bDidSwap = false;

        if (Descending == true)         // If element 1 is less than element 2 move it back in the array (sorts high to low)
        {
            for (k = 0; k < m - a - 1; k++)
            {
                if (Array_To_Sort[k] < Array_To_Sort[k + 1])
                {
                    int32 z;
                    z = Array_To_Sort[k];
                    Array_To_Sort[k] = Array_To_Sort[k + 1];
                    Array_To_Sort[k + 1] = z;
                    bDidSwap = true;
                }
            }

            if (bDidSwap == false)      // If no swaps occured array is sorted do not go through last loop
            {
                break;
            }
        }
        else
        {
            Array_To_Sort.Sort();       // If array will be sorted low to high use Unreal's "Sort" function
        }
    }

    Sorted_Array = Array_To_Sort;
}

void USomnusToolsLibrary::Float_Sort(UPARAM(ref) TArray <float>& Array_To_Sort, bool Descending, TArray <float>& Sorted_Array)
{
    int32 m = Array_To_Sort.Num();      // Return the array size
    int32 a, k;
    bool bDidSwap;

    for (a = 0; a < (m - 1); a++)
    {
        bDidSwap = false;

        if (Descending == true)         // If element 1 is less than element 2 move it back in the array (sorts high to low)
        {
            for (k = 0; k < m - a - 1; k++)
            {
                if (Array_To_Sort[k] < Array_To_Sort[k + 1])
                {
                    float z;
                    z = Array_To_Sort[k];
                    Array_To_Sort[k] = Array_To_Sort[k + 1];
                    Array_To_Sort[k + 1] = z;
                    bDidSwap = true;
                }
            }

            if (bDidSwap == false)      // If no swaps occured array is sorted do not go through last loop
            {
                break;
            }
        }
        else
        {
            Array_To_Sort.Sort();       // If array will be sorted low to high use Unreal's "Sort" function
        }
    }

    Sorted_Array = Array_To_Sort;
}

void USomnusToolsLibrary::String_Sort(UPARAM(ref) TArray <FString>& Array_To_Sort, bool Descending, TArray <FString>& Sorted_Array)
{
    Array_To_Sort.Sort();               // Sort array using built in function (sorts A-Z)

    if (Descending == true)
    {
        TArray <FString> newarray;      // Define "temp" holding array
        int x = Array_To_Sort.Num() - 1;

        while (x > -1)
        {
            newarray.Add(Array_To_Sort[x]); // loop through A-Z sorted array and remove element from back and place it in beginning of "temp" array
            --x;
        }

        Array_To_Sort = newarray;   // Set reference array to "temp" array order, array is now Z-A
    }

    Sorted_Array = Array_To_Sort;
}

//===========================================================================================


//==================================== File Functions ====================================
FString USomnusToolsLibrary::GetSavedDir()
{
    return FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
}


FString USomnusToolsLibrary::GetContentDir()
{
    return FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
     
}
//===========================================================================================

FString USomnusToolsLibrary::GetAppVersion()
{
    FString AppVersion;
    GConfig->GetString(
        TEXT("/Script/EngineSettings.GeneralProjectSettings"),
        TEXT("ProjectVersion"),
        AppVersion,
        GGameIni
    );

    return AppVersion;
}


