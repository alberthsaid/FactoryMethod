// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMaderaMagico.h"


ABloqueMaderaMagico::ABloqueMaderaMagico()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Pine.M_Wood_Pine'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
			MallaBloque->SetRelativeScale3D(FVector(2.0f, 2.0f, 3.5f));
			// MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));*/
		}
	}
}
