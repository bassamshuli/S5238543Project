// Fill out your copyright notice in the Description page of Project Settings.


#include "TileActor.h"

// Sets default values
ATileActor::ATileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// template function that creates a components
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	// every actor has a RootComponent that defines the transform in the World
	SetRootComponent(Scene);
	StaticMeshComponent->SetupAttachment(Scene);

	Status = ETileStatus::EMPTY;
	PlayerOwner = -1;
	TileGridPosition = FVector2D(0, 0);


}

void ATileActor::SetTileStatus(const int32 TileOwner, const ETileStatus TileStatus)
{
	PlayerOwner = TileOwner;
	Status = TileStatus;
}

ETileStatus ATileActor::GetTileStatus()
{
	return Status;
}

int32 ATileActor::GetOwner()
{
	return PlayerOwner;
}

void ATileActor::SetGridPosition(const double InX, const double InY)
{
	TileGridPosition.Set(InX, InY);

}

FVector2D ATileActor::GetGridPosition()
{
	return TileGridPosition;
}

// Called when the game starts or when spawned
void ATileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
//void ATileActor::Tick(float DeltaTime)
//{
	//Super::Tick(DeltaTime);
//
//}

