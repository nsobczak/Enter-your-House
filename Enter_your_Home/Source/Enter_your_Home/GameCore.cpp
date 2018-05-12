// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCore.h"
#include "Blueprint/UserWidget.h"


// Sets default values for this component's properties
UGameCore::UGameCore()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGameCore::BeginPlay()
{
	Super::BeginPlay();
	isGameFinished = false;
}


void UGameCore::GameWin() {
	UE_LOG(LogTemp, Log, TEXT("%s won"), actorThatTrigger);
	isGameFinished = true;
}

// Called every frame
void UGameCore::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!isGameFinished && triggerWin->IsOverlappingActor(actorThatTrigger))
		GameWin();
}

