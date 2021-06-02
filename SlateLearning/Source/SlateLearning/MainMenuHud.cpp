// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHud.h"
#include "Slate/SMainMenuWidget.h"

void AMainMenuHud::PostInitializeComponents()
{
	//TSharedRef必须在定义的时候就赋值，这样写OK
	//TSharedRef<SMainMenuWidget> MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);

	//SAssignNew和SNew的区别是前者返回TSharedPtr，后者返回TSharedRef
	//但是因为TSharedRef可以被隐式转换为TSharedPtr，所以对于TSharedPtr来说用哪个都一样，对于TSharedRef来说只能使用SNew

	//SAssignNew和SNew在写法上有一点点不同，下面两种写法都是ok的
	//MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);
	SAssignNew(MainMenuWidget, SMainMenuWidget).MainMenuHud(this);

	//TSharedPtr转化为TSharedRef需要调用ToSharedRef，反过来则可以直接隐式转换
	GEngine->GameViewport->AddViewportWidgetContent(MainMenuWidget.ToSharedRef());
	
}
