// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman_l01GameMode.h"
#include "Bomberman_l01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "FabricaBloque.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueAgua.h"
#include "BloqueVidrio.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueElectrico.h"
#include "BloqueArena.h"
#include "BloqueBurbuja.h"
#include "BloqueOro.h"
#include "Kismet/GameplayStatics.h"
#include "Bomba.h"
#include "Engine/World.h"
#include "Plataforma.h"
#include "BloqueAceroMagico.h"
#include "BloqueMaderaMagico.h"

ABomberman_l01GameMode::ABomberman_l01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	//if (aEspaciosVaciosBordes.Num() > 0 && MiClaseDePersonaje)
	//{
	//	int32 indiceAleatorio = FMath::RandRange(0, aEspaciosVaciosBordes.Num() - 1);
	//	FVector posicionInicial = aEspaciosVaciosBordes[indiceAleatorio];

	//	// Spawn del personaje

	//	FActorSpawnParameters spawnParams;
	//	APawn* personaje = GetWorld()->SpawnActor<APawn>(MiClaseDePersonaje, posicionInicial, FRotator::ZeroRotator, spawnParams);

	//	// Asignar control
	//	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//	if (PC && personaje)
	//	{
	//		PC->Possess(personaje);
	//	}
	//}
	//int32 filaInicial = 0;  // O cualquier fila de borde que elijas
	//int32 columnaInicial = 0;  // O cualquier columna de borde que elijas

	//FVector posicionInicial = FVector(XInicial + columnaInicial * AnchoBloque, YInicial + filaInicial * LargoBloque, 20.0f);
	//APeonExamen* Peon = GetWorld()->SpawnActor<APeonExamen>(APeonExamen::StaticClass(), posicionInicial, FRotator::ZeroRotator);	GetWorld()->GetTimerManager().SetTimer(TemporizadorInicial, this, &ABomberMan_012025GameMode::IniciarDesaparicionBloquesMadera, 10.0f, false);

}
void ABomberman_l01GameMode::BeginPlay()
{
	FVector SpawnLocation(-399.751f, 0.0f, 0.0f);
	APlataforma* Plataforma = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
	//SpawnBombaEnEspacioVacio();
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));
	aMapaBloques.SetNum(100);
	for (int32 i = 0; i < 100; i++) {
		aMapaBloques[i].SetNum(100);
	}
	for (int32 fila = 0; fila < 100; ++fila)
	{
		for (int32 columna = 0; columna < 100; ++columna)
		{
			if (fila == 0 || fila == 99 || columna == 0 || columna == 99) // Bordes del mapa
			{
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					20.0f);
				SpawnBloque(posicionBloque, 1); // Tipo 1 = BloqueAcero
				aMapaBloques[fila][columna] = 1;
			}
		}
	}
	int32 centroFila = 50; 
	int32 centroColumna = 50; 

	// Línea horizontal
	for (int32 columna = 0; columna < 100; ++columna)
	{
		FVector posicionBloque = FVector(
			XInicial + columna * AnchoBloque,
			YInicial + centroFila * LargoBloque,
			20.0f);
		SpawnBloque(posicionBloque, 1); 
		aMapaBloques[centroFila][columna] = 1;
	}

	// Línea vertical
	for (int32 fila = 0; fila < 100; ++fila)
	{
		FVector posicionBloque = FVector(
			XInicial + centroColumna * AnchoBloque,
			YInicial + fila * LargoBloque,
			20.0f);
		SpawnBloque(posicionBloque, 1); 
		aMapaBloques[fila][centroColumna] = 1;
	}
		GenerarBloquesEnDivision(1, 0, 49, 0, 49, 100*0.4); 
		GenerarBloquesEnDivision(2, 0, 49, 50, 99, 100*0.3); 
		GenerarBloquesEnDivision(3, 50, 99, 0, 49, 100*0.9); 
		GenerarBloquesEnDivision(4, 50, 99, 50, 99, 100*0.5); 

	for (int32 tipo = 1; tipo <= 10; ++tipo)
	{
		int32 fila = FMath::RandRange(0, 99);
		int32 columna = FMath::RandRange(0, 99);

		
		while (aMapaBloques[fila][columna] != 0)
		{
			fila = FMath::RandRange(0, 99);
			columna = FMath::RandRange(0, 99);
		}

		aMapaBloques[fila][columna] = tipo;
	}
	UFabricaBloque* Fabrica = NewObject<UFabricaBloque>();
	
	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{

			int32 valor = aMapaBloques[fila][columna];
			// Calculamos la posición del bloque

			FVector posicionBloque = FVector(
				XInicial + columna * AnchoBloque,
				YInicial + fila * LargoBloque,
				20.0f); // Z queda en 0 (altura del bloque)
			if (valor != 0) // Si no es espacio vacío
			{
				ABloque* NuevoBloque = Fabrica->CrearBloque(GetWorld(), valor, posicionBloque, aBloques, 150.0f, 150.0f);
			}
			else {
				aEspaciosVacios.Add(posicionBloque);
				if (fila == 0 || fila == 84 || columna == 0 || columna == 99) {
					aEspaciosVaciosBordes.Add(posicionBloque);
				}
			}

		}
	}

	if (aEspaciosVaciosBordes.Num() > 0 && MiClaseDePersonaje)
	{
	int32 indiceAleatorio = FMath::RandRange(0, aEspaciosVaciosBordes.Num() - 1);
	FVector posicionInicial = aEspaciosVaciosBordes[indiceAleatorio];

		// Spawn del personaje

		FActorSpawnParameters spawnParams;
		APawn* personaje = GetWorld()->SpawnActor<APawn>(MiClaseDePersonaje, posicionInicial, FRotator::ZeroRotator, spawnParams);

		// Asignar control
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC && personaje)
		{
			PC->Possess(personaje);
		}
	}
	int32 filaInicial = 0;  // O cualquier fila de borde que elijas
	int32 columnaInicial = 0;  // O cualquier columna de borde que elijas

	//FVector posicionInicial = FVector(XInicial + columnaInicial * AnchoBloque, YInicial + filaInicial * LargoBloque, 20.0f);
	//APeonExamen* Peon = GetWorld()->SpawnActor<APeonExamen>(APeonExamen::StaticClass(), posicionInicial, FRotator::ZeroRotator);	GetWorld()->GetTimerManager().SetTimer(TemporizadorInicial, this, &ABomberMan_012025GameMode::IniciarDesaparicionBloquesMadera, 10.0f, false);

	if (aBloques.Num() > 0)
	{
		// Seleccionar un bloque aleatorio de la lista de bloques
		int32 IndiceAleatorio = FMath::RandRange(0, aBloques.Num() - 1);
		ABloque* BloqueSeleccionado = aBloques[IndiceAleatorio];

		if (BloqueSeleccionado)
		{
			// Obtener la posición del bloque seleccionado
			FVector PosicionBloque = BloqueSeleccionado->GetActorLocation();

			// Calcular posiciones adyacentes al bloque
			TArray<FVector> PosicionesAdyacentes = {
				PosicionBloque + FVector(AnchoBloque, 0, 0),  // Derecha
				PosicionBloque - FVector(AnchoBloque, 0, 0),  // Izquierda
				PosicionBloque + FVector(0, LargoBloque, 0),  // Arriba
				PosicionBloque - FVector(0, LargoBloque, 0)   // Abajo
			};

			// Filtrar posiciones válidas (que estén en espacios vacíos)
			TArray<FVector> PosicionesValidas;
			for (const FVector& Posicion : PosicionesAdyacentes)
			{
				if (aEspaciosVacios.Contains(Posicion))
				{
					PosicionesValidas.Add(Posicion);
				}
			}

			// Si hay posiciones válidas, seleccionar una aleatoriamente
			if (PosicionesValidas.Num() > 0)
			{
				int32 IndicePosicion = FMath::RandRange(0, PosicionesValidas.Num() - 1);
				FVector PosicionBomba = PosicionesValidas[IndicePosicion];

				// Spawnear la bomba
				FActorSpawnParameters SpawnParams;
				ABomba* Bomba = GetWorld()->SpawnActor<ABomba>(ABomba::StaticClass(), PosicionBomba, FRotator::ZeroRotator, SpawnParams);

				if (Bomba)
				{
					// Configurar la explosión para que llame a ManejarExplosion
					Bomba->OnExplota.AddDynamic(this, &ABomberman_l01GameMode::ManejarExplosion);
				}
			}
		}
	}
	
}
void ABomberman_l01GameMode::SpawnBloque(FVector posicion, int32 tipoBloque)
{
	// Crear una instancia de la fábrica de bloques
	
}

void ABomberman_l01GameMode::GenerarBloquesEnDivision(int32 division, int32 filaInicio, int32 filaFin, int32 columnaInicio, int32 columnaFin, int32 cantidadBloques)
{
	for (int32 i = 0; i < cantidadBloques; ++i)
	{
		int32 fila = FMath::RandRange(filaInicio, filaFin);
		int32 columna = FMath::RandRange(columnaInicio, columnaFin);

		// Si ya hay un bloque distinto de 0, busca otra posición
		while (aMapaBloques[fila][columna] != 0)
		{
			fila = FMath::RandRange(filaInicio, filaFin);
			columna = FMath::RandRange(columnaInicio, columnaFin);
		}

		int32 tipo = FMath::RandRange(2, 10); // Genera un número aleatorio entre 2 y 10
		aMapaBloques[fila][columna] = tipo;

		FVector posicionBloque = FVector(
			XInicial + columna * AnchoBloque,
			YInicial + fila * LargoBloque,
			20.0f);
		SpawnBloque(posicionBloque, tipo);
	}

	// Mensaje de depuración
	FString mensaje = FString::Printf(TEXT("División %d: Generados %d bloques"), division, cantidadBloques);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, mensaje);
}

void ABomberman_l01GameMode::ManejarExplosion(FVector PosicionExplosion)
{
	// Calcular las posiciones de los bloques en un radio de 2 bloques
	for (int32 OffsetX = -2; OffsetX <= 2; ++OffsetX)
	{
		for (int32 OffsetY = -2; OffsetY <= 2; ++OffsetY)
		{
			FVector PosicionBloque = PosicionExplosion + FVector(OffsetX * AnchoBloque, OffsetY * LargoBloque, 0.0f);

			// Buscar y destruir el bloque en esta posición
			for (int32 i = 0; i < aBloques.Num(); ++i)
			{
				if (aBloques[i] && aBloques[i]->GetActorLocation().Equals(PosicionBloque, 1.0f))
				{
					aBloques[i]->Destroy();
					aBloques.RemoveAt(i);
					break;
				}
			}
		}
	}

}
	
