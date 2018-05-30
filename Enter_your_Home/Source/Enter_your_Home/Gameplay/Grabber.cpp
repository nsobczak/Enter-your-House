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
}


//====================================================================
#pragma region functions
//====================================================================

// look for physicsHandleComponent
void UGrabber::FindPhysicsHandleComponent()
{
	this->physicsHandleComponent = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (nullptr == this->physicsHandleComponent)
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *(GetOwner()->GetName()));
}

// look for and bind action inputComponent
void UGrabber::FindInputComponent()
{
	this->inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (this->inputComponent) {
		//bind actions
		this->inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		this->inputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
		UE_LOG(LogTemp, Error, TEXT("%s missing physics input component"), *(GetOwner()->GetName()));
}

const FVector UGrabber::getReachLineTraceStart()
{
	///get player view point
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation, OUT playerViewPointRotation);
	return playerViewPointLocation;
}

const FVector UGrabber::getReachLineTraceEnd()
{
	///get player view point
	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT playerViewPointLocation, OUT playerViewPointRotation);

	///create lineTraceEnd
	FVector lineTraceEnd = playerViewPointLocation +
		playerViewPointRotation.Vector() * this->reachLimit;
	//DrawDebugLine(GetWorld(), playerViewPointLocation, lineTraceEnd, FColor(0, 0, 255), false, 0, 0, 10);

	return lineTraceEnd;
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	/// line trace = raycast
	FCollisionQueryParams traceParam(FName(TEXT("")), false, GetOwner());
	FHitResult hit;
	GetWorld()->LineTraceSingleByObjectType(OUT hit, getReachLineTraceStart(), getReachLineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), traceParam);
	return hit;
}


// raycasts and grabs what's in reach
void UGrabber::Grab() {
	///line trace and see if we reach any actors with physics body collision channel set
	FHitResult hitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* componentToGrab = hitResult.GetComponent();
	AActor* actorHit = hitResult.GetActor();

	///if we hit smthg then attach a physics handle
	if (actorHit)
		this->physicsHandleComponent->GrabComponentAtLocation(componentToGrab, NAME_None,
			componentToGrab->GetOwner()->GetActorLocation());
};

// grab is released
void UGrabber::Release() {
	this->physicsHandleComponent->ReleaseComponent();
};

#pragma endregion



//====================================================================
#pragma region main functions
//====================================================================

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();
	FindInputComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->physicsHandleComponent->GrabbedComponent)
		this->physicsHandleComponent->SetTargetLocation(getReachLineTraceEnd());

}

#pragma endregion

