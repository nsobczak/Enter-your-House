// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENTER_YOUR_HOME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float closeAngle = 0;
	UPROPERTY(EditAnywhere)
		float openAngle = 90;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* triggerPlate;

	UPROPERTY(EditAnywhere)
		AActor* actorThatOpens;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:
	// Sets default values for this component's properties
	UOpenDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
