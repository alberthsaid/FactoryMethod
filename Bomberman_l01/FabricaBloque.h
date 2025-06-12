// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "FabricaBloque.generated.h"


class ABloque;
UCLASS()
class BOMBERMAN_L01_API UFabricaBloque : public UObject
{
	GENERATED_BODY()
	
public:	

public:	
	ABloque* CrearBloque(UWorld* World, int TipoBloque, FVector Posicion, const TArray<ABloque*>& BloquesExistentes, float DistanciaMinimaX, float DistanciaMinimaY);

};
