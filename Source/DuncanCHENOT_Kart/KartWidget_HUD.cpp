// Fill out your copyright notice in the Description page of Project Settings.


#include "KartWidget_HUD.h"

#include "KartCountDownWidget.h"
#include "Components/TextBlock.h"
#include "KartGameMode.h"
#include "KartPawn.h"

void UKartWidget_HUD::NativeConstruct()
{
	Super::NativeConstruct();
	
	SetVisibility(ESlateVisibility::Collapsed);
	
	if (AKartGameMode* GameMode = GetWorld()->GetAuthGameMode<AKartGameMode>())
	{
		GameMode->OnRaceStarted.AddUniqueDynamic(this, &UKartWidget_HUD::HandleRaceStarted);
		
		if (GameMode->IsRaceStarted())
		{
			HandleRaceStarted();
		}
	}
}

void UKartWidget_HUD::NativeDestruct()
{
	if (UWorld* World =GetWorld())
	{
		if (AKartGameMode* GameMode = World->GetAuthGameMode<AKartGameMode>())
		{
			GameMode->OnRaceStarted.RemoveDynamic(this, &UKartWidget_HUD::HandleRaceStarted);
		}
	}
	Super::NativeDestruct();
}

void UKartWidget_HUD::HandleRaceStarted()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UKartWidget_HUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	const AKartGameMode* GameMode = GetWorld()->GetAuthGameMode<AKartGameMode>();
	const AKartPawn* Kart = GetOwningPlayerPawn<AKartPawn>();
	
	if (GameMode == nullptr || Kart == nullptr)
	{
		return;
	}
	if (!GameMode->IsRaceStarted())
	{
		SetVisibility(ESlateVisibility::Collapsed);
		return;
	}
	if (Kart->HasFinishedRace())
	{
		TimerText->SetText(AKartGameMode::FormatRaceTime(Kart->GetFinishTime()));
		LapText->SetText(FinishedText);
	}
	else
	{
		TimerText->SetText(AKartGameMode::FormatRaceTime(GameMode->GetRaceTime()));
		LapText->SetText(FText::Format(NSLOCTEXT("Kart", "LapFormat", "Tour {0}/{1}"),FText::AsNumber(Kart->GetCurrentLap()), FText::AsNumber(GameMode->GetLapCount())));
	}
}
