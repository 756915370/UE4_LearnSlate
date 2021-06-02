// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHud.h"
#include "Slate/SMainMenuWidget.h"

void AMainMenuHud::PostInitializeComponents()
{
	//TSharedRef�����ڶ����ʱ��͸�ֵ������дOK
	//TSharedRef<SMainMenuWidget> MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);

	//SAssignNew��SNew��������ǰ�߷���TSharedPtr�����߷���TSharedRef
	//������ΪTSharedRef���Ա���ʽת��ΪTSharedPtr�����Զ���TSharedPtr��˵���ĸ���һ��������TSharedRef��˵ֻ��ʹ��SNew

	//SAssignNew��SNew��д������һ��㲻ͬ����������д������ok��
	//MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);
	SAssignNew(MainMenuWidget, SMainMenuWidget).MainMenuHud(this);

	//TSharedPtrת��ΪTSharedRef��Ҫ����ToSharedRef�������������ֱ����ʽת��
	GEngine->GameViewport->AddViewportWidgetContent(MainMenuWidget.ToSharedRef());
	
}
