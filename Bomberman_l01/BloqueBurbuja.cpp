// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueBurbuja.h"

ABloqueBurbuja::ABloqueBurbuja()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Poured.M_Concrete_Poured'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
		}
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;

	bPuedeMoverse = FMath::RandBool();

}