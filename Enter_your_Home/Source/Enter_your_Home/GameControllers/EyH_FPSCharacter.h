// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h" 
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Gameplay/StartCountdown.h"
#include "Gameplay/Grabber.h"
#include "ConstructorHelpers.h"
#include "EyH_FPSCharacter.generated.h"

UCLASS()
class ENTER_YOUR_HOME_API AEyH_FPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Constructor for AFPSCharacter
	AEyH_FPSCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// === Components ===
	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FPSCamera;
	UPROPERTY(VisibleAnywhere)
		UGrabber* Grabber;	

	// === Input ===
	/**handles moving forward/backward*/
	UFUNCTION()
		void MoveForward(float Val);
	/**handles strafing*/
	UFUNCTION()
		void MoveRight(float Val);

	/**sets jump flag when key is pressed*/
	UFUNCTION()
		void OnStartJump();
	/**clears jump flag when key is released*/
	UFUNCTION()
		void OnStopJump();
};
