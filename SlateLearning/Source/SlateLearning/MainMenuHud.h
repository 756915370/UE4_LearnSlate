// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHud.generated.h"

/**
 * 
 */
UCLASS()
class SLATELEARNING_API AMainMenuHud : public AHUD
{
	GENERATED_BODY()

	virtual void PostInitializeComponents() override;

    TSharedPtr<class SMainMenuWidget> MainMenuWidget;
public:
    // Called by SMainMenu whenever the Play Game! button has been clicked.
    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
        void PlayGameClicked();

    // Called by SMainMenu whenever the Quit Game button has been clicked.
    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
        void QuitGameClicked();
};
