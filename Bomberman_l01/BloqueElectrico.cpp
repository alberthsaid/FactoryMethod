// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueElectrico.h"

ABloqueElectrico::ABloqueElectrico()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
		}
	}
	FloatSpeed = 2.0f;
	RotationSpeed = 3.0f;

	bPuedeMoverse = FMath::RandBool();
}

void ABloqueElectrico::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueElectrico::Tick(float DeltaTime)
{
	/*if (bPuedeMoverse)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.X =PosicionInicial.X+ FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		NewLocation.Y =PosicionInicial.Y+ FMath::Cos(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		SetActorLocation(NewLocation);
	}*/
	if (bPuedeMoverse)
	{
		FVector NewLocation = PosicionInicial;
		NewLocation.Z = FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 120.0f;
		SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = PosicionInicial;
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 50.0f;
		SetActorLocation(NewLocation);
	}
}
