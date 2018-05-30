// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MenuController.generated.h"

UCLASS()
class ENTER_YOUR_HOME_API AMenuController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMenuController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int activeWidgetIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
