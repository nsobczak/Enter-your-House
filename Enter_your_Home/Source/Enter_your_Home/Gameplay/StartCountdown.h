// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "StartCountdown.generated.h"

UCLASS()
class ENTER_YOUR_HOME_API AStartCountdown : public AActor
{
	GENERATED_BODY()

public:
	AStartCountdown();

	//How often, in seconds, should the countdown be called
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float timerUpdateFreq = 1.0f;
	//How long the countdown will run
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 countdownTime = 3;
	/*UPROPERTY(EditAnywhere)
		float _worldSize_ = 150.0f;
*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText countdownFinishedText;
	UPROPERTY(BlueprintReadWrite)
		bool isCountdownFinished = false;

	UPROPERTY(EditAnywhere)
		UTextRenderComponent* CountdownText;
	FTimerHandle CountdownTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//____________________________________________
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateTimerDisplay();
	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
		void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();
};
