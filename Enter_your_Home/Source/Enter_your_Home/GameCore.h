// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/TriggerVolume.h"
#include "GameCore.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENTER_YOUR_HOME_API UGameCore : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* triggerWin;

	UPROPERTY(EditAnywhere)
		AActor* actorThatTrigger;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void GameWin();

public:
	// Sets default values for this component's properties
	UGameCore();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



};
