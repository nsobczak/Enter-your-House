// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	//Super::BeginPlay();

	// ...

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	///get player view point
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation, OUT playerViewPointRotation);

	///create lineTraceEnd
	FVector lineTraceEnd = playerViewPointLocation +
		playerViewPointRotation.Vector() * this->reachLimit;
	DrawDebugLine(GetWorld(), playerViewPointLocation, lineTraceEnd,
		FColor(0, 0, 255), false, 0, 0, 10);

	///raycast
	FCollisionQueryParams traceParam(FName(TEXT("")), false, GetOwner());
	FHitResult hit;
	GetWorld()->LineTraceSingleByObjectType(OUT hit, playerViewPointLocation, lineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), traceParam);
	AActor* hitObject = hit.GetActor();
	if (hitObject)
		UE_LOG(LogTemp, Warning, TEXT("hit object: %s"), *(hitObject->GetName()) );
}

