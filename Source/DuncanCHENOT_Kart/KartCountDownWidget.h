// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KartCountDownWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class DUNCANCHENOT_KART_API UKartCountDownWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CountDownText;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kart|CountDown")
	FText GoText = NSLOCTEXT("Kart", "Go", "GO!");
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kart|CountDown", meta = (ClampMin = "0"))
	float GoDisplayTime = 1.f;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Kart|CountDown")
	void OnCountdownNumberShown(int32 Number);
	
private:
	UFUNCTION()
	void HandleCountdownTick(int32 Number);
	
	void HideCountdown();
	
	FTimerHandle HideTimer;
};
