// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueVidrio.h"
ABloqueVidrio::ABloqueVidrio()
{
	// Set this actor to call Tick() every frame.
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
			/*MallaBloque->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
			MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));*/
		}
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;
	bPuedeMoverse = false;
}
void ABloqueVidrio::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueVidrio::Tick(float DeltaTime)
{
	if (bPuedeMoverse)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		NewLocation.Y = PosicionInicial.Y + FMath::Cos(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		SetActorLocation(NewLocation);
	}
}
