// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAgua.h"

ABloqueAgua::ABloqueAgua()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'"));
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
void ABloqueAgua::BeginPlay()
{
	Super::BeginPlay();
}

