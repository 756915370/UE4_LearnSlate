// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHud.h"
#include "Slate/SMainMenuWidget.h"

void AMainMenuHud::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuWidget, SMainMenuWidget).MainMenuHud(this);

	
	GEngine->GameViewport->AddViewportWidgetContent(MainMenuWidget.ToSharedRef());
	
}
