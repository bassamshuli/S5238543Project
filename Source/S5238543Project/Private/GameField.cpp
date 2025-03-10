// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"

// Sets default values
AGameField::AGameField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// size of the field (3x3)
	Size = 25;
	// tile dimension
	TileSize = 100.f;


}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
	Super::BeginPlay();
	GenerateField();
}

// Called every frame
//void AGameField::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AGameField::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	//normalized tilepadding
	NextCellPositionMultiplier = ( TileSize + 1.3)/(TileSize); 
}

void AGameField::ResetField()
{
}

void AGameField::GenerateField()
{
	for (int32 IndexX =-12; IndexX < Size-12; IndexX++)
	{
		for (int32 IndexY = -12; IndexY < Size-12; IndexY++)
		{
			FVector Location = AGameField::GetRelativeLocationByXYPosition(IndexX, IndexY);
			ATileActor* Obj = GetWorld()->SpawnActor<ATileActor>(TileClass, Location, FRotator::ZeroRotator);
			const float TileScale = TileSize / 100.f;
			const float Zscaling = 0.01f;
			Obj->SetActorScale3D(FVector(TileScale, TileScale, Zscaling));
			Obj->SetGridPosition(IndexX, IndexY);
			TileArray.Add(Obj);
			TileMap.Add(FVector2D(IndexX, IndexY), Obj);
		}
	}
}

FVector2D AGameField::GetPosition(const FHitResult& Hit)
{
	return Cast<ATileActor>(Hit.GetActor())->GetGridPosition();
}

TArray<ATileActor*>& AGameField::GetTileArray()
{
	return TileArray;
}

FVector AGameField::GetRelativeLocationByXYPosition(const int32 InX, const int32 InY) const
{
	return TileSize * NextCellPositionMultiplier * FVector(InX, InY, 0);
}

FVector2D AGameField::GetXYPositionByRelativeLocation(const FVector& Location) const
{
	const double XPos = Location.X / (TileSize * NextCellPositionMultiplier);
	const double YPos = Location.Y / (TileSize * NextCellPositionMultiplier);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("x=%f,y=%f"), XPos, YPos));
	return FVector2D(XPos, YPos);
}

bool AGameField::IsWinPosition(const FVector2D Position) const
{
	return false;
}

inline bool AGameField::IsWinLine(const FVector2D Begin, const FVector2D End) const
{
	return false;
}

inline bool AGameField::IsValidPosition(const FVector2D Position) const
{
	return false;
}

TArray<int32> AGameField::GetLine(const FVector2D Begin, const FVector2D End) const
{
	return TArray<int32>();
}

bool AGameField::AllEqual(const TArray<int32>& Array) const
{
	return false;
}
