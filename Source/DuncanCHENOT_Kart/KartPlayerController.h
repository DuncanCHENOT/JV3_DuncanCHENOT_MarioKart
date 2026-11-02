// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KartCountDownWidget.h"
#include "KartWidget_HUD.h"
#include "GameFramework/PlayerController.h"
#include "KartPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DUNCANCHENOT_KART_API AKartPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Kart|UI")
	TSubclassOf<UKartCountDownWidget> CountDownWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Kart|UI")
	TSubclassOf<UKartWidget_HUD> HUDWidgetClass;
	
private:
	UPROPERTY()
	TObjectPtr<UKartCountDownWidget> CountDownWidget;
	UPROPERTY()
	TObjectPtr<UKartWidget_HUD> HUDWidget;
};
