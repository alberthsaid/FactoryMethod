// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	MallaPlataforma->SetupAttachment(RootComponent);
	if (MeshAsset.Succeeded())
	{
		MallaPlataforma->SetStaticMesh(MeshAsset.Object);
		MallaPlataforma->SetRelativeScale3D(FVector(222.75f, 222.75f, 1.0f));
		MallaPlataforma->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
	if (MallaPlataforma)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));
		if (Material.Succeeded())
		{
			MallaPlataforma->SetMaterial(0, Material.Object);
		}
	}

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

