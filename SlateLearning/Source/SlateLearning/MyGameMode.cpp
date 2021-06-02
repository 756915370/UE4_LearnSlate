// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

#include "MainMenuHud.h"

AMyGameMode::AMyGameMode()
{
	HUDClass = AMainMenuHud::StaticClass();
}
