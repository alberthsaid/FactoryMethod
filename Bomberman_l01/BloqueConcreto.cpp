// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"
 
ABloqueConcreto::ABloqueConcreto()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime'"));
	if (Material.Succeeded())
	{
		MallaBloque->SetMaterial(0, Material.Object);
		/*MallaBloque->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
		MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));*/
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;
	bPuedeMoverse = false;
}
void ABloqueConcreto::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueConcreto::Tick(float DeltaTime)
{
	if (bPuedeMoverse)
	{
		FVector NewLocation = PosicionInicial;
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f;
		SetActorLocation(NewLocation);
	}
}
