// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "EyH_GameMode.generated.h"


UENUM(BlueprintType)        //"BlueprintType" is essential specifier
enum GraphicLabel
{
	Graphical, PP, AA, Shadow, FPS
};

UCLASS()
class ENTER_YOUR_HOME_API AEyH_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = "Game_Settings")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	/** Decrease if increase is false */
	UFUNCTION(BlueprintCallable, Category = "Game_Settings")
		void ChangeGraphicSetting(GraphicLabel graphicLabel, bool increase);


	////labels
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game_Settings") FText MainSettingsLabel[4];
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game_Settings") FText FPSSettingsLabel[4];

	//commands
	UPROPERTY(EditAnywhere, Category = "Game_Settings") FString GraphicalCommands[4] = { "r.ScreenPercentage 25", "r.ScreenPercentage 50","r.ScreenPercentage 75","r.ScreenPercentage 100" };
	TArray<FString> TAGraphicalCommands;
	UPROPERTY(EditAnywhere, Category = "Game_Settings") FString PPCommands[4] = { "sg.PostProcessQuality 0","sg.PostProcessQuality 1", "sg.PostProcessQuality 2", "sg.PostProcessQuality 3" };
	TArray<FString> TAPPCommands;
	UPROPERTY(EditAnywhere, Category = "Game_Settings") FString AACommands[4] = { "r.PostProcessAAQuality 0","r.PostProcessAAQuality 1", "r.PostProcessAAQuality 2", "r.PostProcessAAQuality 3" };
	TArray<FString> TAAACommands;
	UPROPERTY(EditAnywhere, Category = "Game_Settings") FString ShadowCommands[4] = { "sg.ShadowQuality 0","sg.ShadowQuality 1", "sg.ShadowQuality 2", "sg.ShadowQuality 3" };
	TArray<FString> TAShadowCommands;
	UPROPERTY(EditAnywhere, Category = "Game_Settings") FString FPSCommands[4] = { "t.MaxFPS 15","t.MaxFPS 30", "t.MaxFPS 60", "t.MaxFPS 144" };
	TArray<FString> TAFPSCommands;

	//indexes
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game_Settings")
		int32 GraphicalIndex = 2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game_Settings")
		int32 PPIndex = 2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game_Settings")
		int32 AAIndex = 2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game_Settings")
		int32 ShadowIndex = 2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game_Settings")
		int32 FPSIndex = 2;

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Menu_Settings")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;

};