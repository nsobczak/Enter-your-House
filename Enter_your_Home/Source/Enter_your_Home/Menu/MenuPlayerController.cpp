// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuPlayerController.h"

// Called when the game starts or when spawned
void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("wMainMenuPlayerController"));

	if (wMainMenu) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

		//now you can use the widget directly since you have a referance for it.
		//	Extra check to  make sure the pointer holds the widget.
		if (MyMainMenu)
			MyMainMenu->AddToViewport();

		//Show the Cursor.
		bShowMouseCursor = true;
	}
}

