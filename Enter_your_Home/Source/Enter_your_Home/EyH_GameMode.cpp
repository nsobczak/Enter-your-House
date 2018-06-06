// Fill out your copyright notice in the Description page of Project Settings.

#include "EyH_GameMode.h"


void AEyH_GameMode::BeginPlay()
{
	Super::BeginPlay();

	//label
	TArray<FString> tmpMainSettingsLabel;
	tmpMainSettingsLabel.Append(MainSettingsLabel, ARRAY_COUNT(MainSettingsLabel));
	for (size_t i = 0; i < tmpMainSettingsLabel.Num(); i++)
	{
		TAMainSettingsLabel.Add(FText::FromString(tmpMainSettingsLabel[i]));
	}

	TArray<FString> tmpFPSSettingsLabel;
	tmpFPSSettingsLabel.Append(FPSSettingsLabel, ARRAY_COUNT(FPSSettingsLabel));
	for (size_t i = 0; i < tmpFPSSettingsLabel.Num(); i++)
	{
		TAFPSSettingsLabel.Add(FText::FromString(tmpFPSSettingsLabel[i]));
	}

	//command
	TAGraphicalCommands.Append(GraphicalCommands, ARRAY_COUNT(GraphicalCommands));
	TAPPCommands.Append(GraphicalCommands, ARRAY_COUNT(PPCommands));
	TAAACommands.Append(GraphicalCommands, ARRAY_COUNT(AACommands));
	TAShadowCommands.Append(GraphicalCommands, ARRAY_COUNT(ShadowCommands));
	TAFPSCommands.Append(GraphicalCommands, ARRAY_COUNT(FPSCommands));

	//widget
	ChangeMenuWidget(StartingWidgetClass);
}


void AEyH_GameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("current widget not null"));

		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AEyH_GameMode::ChangeGraphicSetting(GraphicLabel graphicLabel, bool increase) {
	TArray <FString> commandList;
	int32 commandIndex;

	//index
	switch (graphicLabel)
	{
	case Graphical:
		increase ? ++GraphicalIndex : --GraphicalIndex;
		commandList = TAGraphicalCommands;
		GraphicalIndex = (GraphicalIndex > commandList.Num() - 1) ? commandList.Num() - 1 :
			(GraphicalIndex < 0) ? 0 : GraphicalIndex;
		commandIndex = GraphicalIndex;
		break;

	case PP:
		increase ? ++PPIndex : --PPIndex;
		commandList = TAPPCommands;
		PPIndex = (PPIndex > commandList.Num() - 1) ? commandList.Num() - 1 :
			(PPIndex < 0) ? 0 : PPIndex;
		commandIndex = PPIndex;
		break;

	case AA:
		increase ? ++AAIndex : --AAIndex;
		commandList = TAAACommands;
		AAIndex = (AAIndex > commandList.Num() - 1) ? commandList.Num() - 1 :
			(AAIndex < 0) ? 0 : AAIndex;
		commandIndex = AAIndex;
		break;

	case Shadow:
		increase ? ++ShadowIndex : --ShadowIndex;
		commandList = TAShadowCommands;
		ShadowIndex = (ShadowIndex > commandList.Num() - 1) ? commandList.Num() - 1 :
			(ShadowIndex < 0) ? 0 : ShadowIndex;
		commandIndex = ShadowIndex;
		break;

	case FPS:
		increase ? ++FPSIndex : --FPSIndex;
		commandList = TAFPSCommands;
		FPSIndex = (FPSIndex > commandList.Num() - 1) ? commandList.Num() - 1 :
			(FPSIndex < 0) ? 0 : FPSIndex;
		commandIndex = FPSIndex;
		break;

	default:
		break;
	}

	//command
	GetWorld()->Exec(GetWorld(), *(commandList[commandIndex]));
}