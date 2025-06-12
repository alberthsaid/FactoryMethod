// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueOro.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_L01_API ABloqueOro : public ABloque
{
	GENERATED_BODY()
public:
	ABloqueOro();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	
};
