// Fill out your copyright notice in the Description page of Project Settings.

#include "StartCountdown.h"


// Sets default values
AStartCountdown::AStartCountdown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	//CountdownText->SetWorldSize(_worldSize_);
	RootComponent = CountdownText;
}

// Called when the game starts or when spawned
void AStartCountdown::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AStartCountdown"));

	isCountdownFinished = false;
	//adding a call to update function
	UpdateTimerDisplay();
	//set a timer to advance and update the countdown once per second
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AStartCountdown::AdvanceTimer, timerUpdateFreq, true);
}

// Called every frame
void AStartCountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStartCountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(countdownTime, 0)));
}


void AStartCountdown::AdvanceTimer()
{
	--countdownTime;
	UpdateTimerDisplay();

	//We're done counting down, so stop running the timer.
	if (countdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void AStartCountdown::CountdownHasFinished_Implementation()
{
	//Change to a special readout
	CountdownText->SetText(countdownFinishedText);
	isCountdownFinished = true;
}
