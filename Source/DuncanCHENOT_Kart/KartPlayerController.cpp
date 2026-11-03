// Fill out your copyright notice in the Description page of Project Settings.


#include "KartPlayerController.h"

#include "KartCountdownWidget.h"
#include "KartWidget_HUD.h"

void AKartPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// L'UI n'existe que pour le joueur qui joue sur cette machinex
	if (!IsLocalController())
	{
		return;
	}

	if (CountDownWidgetClass != nullptr)
	{
		CountDownWidget = CreateWidget<UKartCountDownWidget>(this, CountDownWidgetClass);
		if (CountDownWidget != nullptr)
		{
			CountDownWidget->AddToViewport();
		}
	}

	if (HUDWidgetClass != nullptr)
	{
		HUDWidget = CreateWidget<UKartWidget_HUD>(this, HUDWidgetClass);
		if (HUDWidget != nullptr)
		{
			HUDWidget->AddToViewport();
		}
	}
}