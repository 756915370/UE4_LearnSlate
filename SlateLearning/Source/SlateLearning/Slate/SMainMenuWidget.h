// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 *
 */
class SLATELEARNING_API SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget)
	{
	}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHud>, MainMenuHud)
	SLATE_END_ARGS()

public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	// Click handler for the Play Game! button ¨C Calls MenuHUD¡¯s PlayGameClicked() event.
	FReply PlayGameClicked();

	// Click handler for the Quit Game button ¨C Calls MenuHUD¡¯s QuitGameClicked() event.
	FReply QuitGameClicked();

};
