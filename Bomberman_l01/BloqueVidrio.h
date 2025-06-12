// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueVidrio.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_L01_API ABloqueVidrio : public ABloque
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ABloqueVidrio();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	
};
