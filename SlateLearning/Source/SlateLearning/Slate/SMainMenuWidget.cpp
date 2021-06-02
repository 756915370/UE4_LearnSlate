// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::White)
			.Text(FText::FromString("Main Menu"))
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[	SNew(SButton)
				.Text(FText::FromString("Play Game"))
				.OnClicked(this, &SMainMenuWidget::PlayGameClicked)
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Quit Game"))
				.OnClicked(this,&SMainMenuWidget::QuitGameClicked)
			]
		]
	];
	
}

FReply SMainMenuWidget::PlayGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("PlayGameClicked"));
	}
	return FReply::Handled();
}

FReply SMainMenuWidget::QuitGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked"));
	}
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
