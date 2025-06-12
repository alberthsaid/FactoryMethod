// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"

ABloqueLadrillo::ABloqueLadrillo()
{
	// Set this actor to call Tick() every frame.
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
			/*MallaBloque->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
			MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));*/
		}
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;
	bPuedeMoverse = FMath::RandBool();
}
void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueLadrillo::Tick(float DeltaTime)
{
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