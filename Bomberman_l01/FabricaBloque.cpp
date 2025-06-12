// Fill out your copyright notice in the Description page of Project Settings.


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
#include "BloqueAceroMagico.h"
#include "BloqueMaderaMagico.h"


ABloque* UFabricaBloque::CrearBloque(UWorld* World, int TipoBloque, FVector Posicion, const TArray<ABloque*>& BloquesExistentes, float DistanciaMinimaX, float DistanciaMinimaY)
{
    if (!World) return nullptr;

    TSubclassOf<ABloque> ClaseBloque = nullptr;

	switch (TipoBloque)
	{
	case 1:
		ClaseBloque = ABloqueAcero::StaticClass();
		break;
	case 2: ClaseBloque = ABloqueConcreto::StaticClass();
		break;
	case 3: ClaseBloque = ABloqueAgua::StaticClass();
		break;
	case 4: ClaseBloque = ABloqueLadrillo::StaticClass();
		break;
	case 5: ClaseBloque = ABloqueBurbuja::StaticClass();
		break;
	case 6: ClaseBloque = ABloqueMadera::StaticClass();
		break;
	case 7: ClaseBloque = ABloqueElectrico::StaticClass();
		break;
	case 8: ClaseBloque = ABloqueOro::StaticClass();
		break;
	case 9: ClaseBloque = ABloqueVidrio::StaticClass();
		break;
	case 10: ClaseBloque = ABloqueArena::StaticClass();
		break;
	case 11: ClaseBloque = ABloqueAceroMagico::StaticClass();
		break;
	case 12: ClaseBloque = ABloqueMaderaMagico::StaticClass();
		break;
	default:
        UE_LOG(LogTemp, Warning, TEXT("Tipo de bloque inválido: %d"), TipoBloque);
        return nullptr;
    }

    return World->SpawnActor<ABloque>(ClaseBloque, Posicion, FRotator::ZeroRotator);

		bool bEspacioValido = true;
		for (ABloque* BloqueExistente : BloquesExistentes)
		{
			if (BloqueExistente)
			{
				FVector PosicionExistente = BloqueExistente->GetActorLocation();
				if (FMath::Abs(PosicionExistente.X - Posicion.X) < DistanciaMinimaX &&
					FMath::Abs(PosicionExistente.Y - Posicion.Y) < DistanciaMinimaY)
				{
					bEspacioValido = false;
					break;
				}
			}
		}
		if (bEspacioValido)
		{
			return CrearBloque(World, TipoBloque, Posicion, BloquesExistentes, DistanciaMinimaX, DistanciaMinimaY); // Llama a tu método original de creación
		}
		return nullptr;
}

