// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MallaBomba = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBomba"));
	RootComponent = MallaBomba;

	// Asignar una malla estática (reemplaza con la ruta de tu malla)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombaMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	if (BombaMesh.Succeeded())
	{
		MallaBomba->SetStaticMesh(BombaMesh.Object);
		MallaBomba->SetRelativeScale3D(FVector(2.5f, 2.5f, 2.5f)); // Escalar la malla
		MallaBomba->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}

	// Configurar valores predeterminados
	TiempoParaExplotar = 4.0f; // 3 segundos antes de explotar
	RadioExplosion = 300.0f;

}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	// Configurar un temporizador para la explosión
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle_Explosion,
		this,
		&ABomba::Explotar,
		TiempoParaExplotar,
		false
	);
	
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABomba::Explotar()
{
	// Mostrar un mensaje en pantalla
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("¡BOOM!"));
	OnExplota.Broadcast(GetActorLocation());

	// Aplicar daño en el radio de la explosión
	UGameplayStatics::ApplyRadialDamage(
		this,
		50.0f, // Cantidad de daño
		GetActorLocation(),
		RadioExplosion,
		nullptr,
		TArray<AActor*>(), // Actores ignorados
		this,
		GetInstigatorController(),
		true
	);

	OnExplota.Broadcast(GetActorLocation());
	Destroy();
}


