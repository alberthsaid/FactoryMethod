// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomba.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExplota, FVector, PosicionExplosion);
UCLASS()
class BOMBERMAN_L01_API ABomba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

		// Componente de malla para la bomba
		UStaticMeshComponent* MallaBomba;

		FTimerHandle TimerHandle_Explosion;

		float TiempoParaExplotar;
		float RadioExplosion;
		void Explotar();

public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		UPROPERTY(BlueprintAssignable, Category = "Eventos")

		FOnExplota OnExplota;

};