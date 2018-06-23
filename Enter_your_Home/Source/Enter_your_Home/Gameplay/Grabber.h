// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENTER_YOUR_HOME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()


private:
	UPROPERTY(EditAnywhere)
		float reachLimit = 400;

	UPhysicsHandleComponent* physicsHandleComponent = nullptr;

	UInputComponent* inputComponent = nullptr;

	//raycasts and grabs what's in reach
	void Grab();
	//grab is released
	void Release();


protected:
	void FindPhysicsHandleComponent();
	void FindInputComponent();

	const FVector getReachLineTraceStart();
	const FVector getReachLineTraceEnd();

	const FHitResult GetFirstPhysicsBodyInReach();

	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
