// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KartPlayerController.generated.h"

class UKartCountDownWidget;
class UKartWidget_HUD;
class UInputMappingContext;
class UInputAction;
class AKartPawn;
struct FInputActionValue;

UCLASS()
class DUNCANCHENOT_KART_API AKartPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditAnywhere, Category = "Kart|UI")
	TSubclassOf<UKartCountDownWidget> CountDownWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Kart|UI")
	TSubclassOf<UKartWidget_HUD> HUDWidgetClass;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputMappingContext> KartMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputAction> ThrottleAction;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputAction> SteerAction;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputAction> DriftAction;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditAnywhere, Category = "Kart|Input")
	TObjectPtr<UInputAction> UseItemAction;
	
private:
	void OnThrottle(const FInputActionValue& Value);
	void OnThrottleReleased(const FInputActionValue& Value);
	void OnSteer(const FInputActionValue& Value);
	void OnSteerReleased(const FInputActionValue& Value);
	void OnDriftPressed(const FInputActionValue& Value);
	void OnDriftReleased(const FInputActionValue& Value);
	void OnJumpPressed(const FInputActionValue& Value);
	void OnUseItemPressed(const FInputActionValue& Value);
	
	AKartPawn* GetKart() const;
	
	UPROPERTY()
	TObjectPtr<UKartCountDownWidget> CountDownWidget;
	UPROPERTY()
	TObjectPtr<UKartWidget_HUD> HUDWidget;
};
