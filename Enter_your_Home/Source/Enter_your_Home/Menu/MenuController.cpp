// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuController.h"


// Sets default values
AMenuController::AMenuController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMenuController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("wMainMenuController"));
}

// Called every frame
void AMenuController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

