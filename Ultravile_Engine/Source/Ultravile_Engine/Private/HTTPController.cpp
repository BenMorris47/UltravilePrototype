// Fill out your copyright notice in the Description page of Project Settings.


#include "HTTPController.h"

void UHTTPController::CallHTML(FString url,bool& Sucess)
{
	FHttpRequestRef request = FHttpModule::Get().CreateRequest();
	request->SetURL(url);
	request->SetVerb("GET");
	request->ProcessRequest();
	
}

