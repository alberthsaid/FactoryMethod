// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"

 ABloqueAcero::ABloqueAcero()
{
	 if (MallaBloque)
	 {
		 static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
		 if (Material.Succeeded())
		 {
			 MallaBloque->SetMaterial(0, Material.Object);
			 MallaBloque->SetRelativeScale3D(FVector(2.0f, 2.0f, 3.5f));
			// MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));*/
		 }
	 }
}
 void ABloqueAcero::BeginPlay()
 {
	 Super::BeginPlay();
	 
 }

