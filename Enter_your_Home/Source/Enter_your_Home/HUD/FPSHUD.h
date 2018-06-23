// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine.h"
#include "FPSHUD.generated.h"

/**
 *
 */
UCLASS()
class ENTER_YOUR_HOME_API AFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSHUD(const FObjectInitializer& ObjectInitializer);


private:
	/** Crosshair asset pointer */
	UTexture2D * CrosshairTex;

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
};
