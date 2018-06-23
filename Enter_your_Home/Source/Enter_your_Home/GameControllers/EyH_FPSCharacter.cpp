// Fill out your copyright notice in the Description page of Project Settings.

#include "EyH_FPSCharacter.h"


// Sets default values
AEyH_FPSCharacter::AEyH_FPSCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = GetCapsuleComponent();

	// === CameraComponent === 
	FPSCamera = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FPSCamera->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	FPSCamera->RelativeLocation = FVector(0, 0, 50.0f + BaseEyeHeight);// Position the camera a bit above the eyes
	FPSCamera->RelativeRotation.Pitch = 0;
	FPSCamera->bUsePawnControlRotation = true; // Allow the pawn to control rotation.

	// === grabber ===
	//Grabber = ObjectInitializer.CreateDefaultSubobject<UGrabber>(this, TEXT("Grabber"));
	//AddOwnedComponent(Grabber);

	// === Countdown === AActor
	//Countdown = ObjectInitializer.CreateDefaultSubobject<AStartCountdown>(this, TEXT("Countdown_test"));
	//Countdown->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Countdown->SetActorTickEnabled(true);
	//Countdown->SetupAttachement(GetRootComponent());
}


// Called when the game starts or when spawned
void AEyH_FPSCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEyH_FPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


#pragma region Input
//____________________________________________________________________________________

// Called to bind functionality to input
void AEyH_FPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &AEyH_FPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEyH_FPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AEyH_FPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AEyH_FPSCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AEyH_FPSCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AEyH_FPSCharacter::OnStopJump);
}

void AEyH_FPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AEyH_FPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AEyH_FPSCharacter::OnStartJump()
{
	bPressedJump = true;
}
void AEyH_FPSCharacter::OnStopJump()
{
	bPressedJump = false;
}

//____________________________________________________________________________________
#pragma endregion
