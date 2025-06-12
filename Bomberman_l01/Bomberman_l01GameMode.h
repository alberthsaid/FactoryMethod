// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Bomberman_l01GameMode.generated.h"
class ABloque;
class ABomba;
UCLASS(minimalapi)
class ABomberman_l01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberman_l01GameMode();
protected:
	virtual void BeginPlay() override;

public:
	// Declarar la posición del siguiente bloque
	FVector posicionSiguienteBloque = FVector(1000.0f, 500.0f, 130.0f);

	// Declarar un mapa de bloques como un array bidimensional
	TArray<TArray<int32>> aMapaBloques;
	
	TArray<ABloque*> aBloques;
	float XInicial = -2500.00f;
	float YInicial = -2500.00f;
	float AnchoBloque = 100.0f;
	float LargoBloque = 100.0f;
	TSubclassOf<APawn> MiClaseDePersonaje;
	ABloque* BloqueActual = nullptr;
	// Declarar un array de punteros a objetos de tipo BloqueMadera
	FTimerHandle TemporizadorInicial;
	TArray<FVector> aEspaciosVacios;
	FTimerHandle tHDestruirBloques;
	TArray<FVector> aEspaciosVaciosBordes;
	TArray<ABloque*> aBloquesLadrillo;
	//void SpawnPersonaje();
	void SpawnBloque(FVector posicion, int32 tipoBloque);
	void ManejarExplosion(FVector PosicionExplosion);
	void GenerarBloquesEnDivision(int32 division, int32 filaInicio, int32 filaFin, int32 columnaInicio, int32 columnaFin, int32 cantidadBloques);
	
};



