// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"

#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENTER_YOUR_HOME_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int activeWidgetIndexChild = 0;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wMainMenu;

	// Variable to hold the widget After Creating it.
	UPROPERTY(EditAnywhere)
	UUserWidget* MyMainMenu;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
