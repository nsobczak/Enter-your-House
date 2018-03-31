// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor()
{
	AActor* owner = GetOwner();
	FRotator newRotation = FRotator(0, this->openAngle, 0);
	owner->SetActorRotation(newRotation);
}

void UOpenDoor::CloseDoor()
{
	AActor* owner = GetOwner();
	FRotator newRotation = FRotator(0, this->closeAngle, 0);
	owner->SetActorRotation(newRotation);
}



// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (triggerPlate->IsOverlappingActor(actorThatOpens))
		OpenDoor();
	else if (GetOwner()->GetActorRotation().Yaw != this->closeAngle)
		CloseDoor();
}

