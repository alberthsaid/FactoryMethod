// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN_L01_API ABloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloque();
	UStaticMeshComponent* MallaBloque;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float FloatSpeed;
	float RotationSpeed;
	bool bPuedeMoverse;
	FVector PosicionInicial;
	//virtual void Protegerse() = 0;
	static ABloque* CreateBloque(UWorld* World, const FVector& Location, const FRotator& Rotation)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		return World->SpawnActor<ABloque>(Location, Rotation, SpawnParams);
	}
	//static ABloque* CrearBloque(FString TipoBloque);
	//PURE_VIRTUAL(ABloque::CrearBloque, return nullptr;);
};
