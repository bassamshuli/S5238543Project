// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileActor.generated.h"

UENUM()
enum class ETileStatus : uint8
{
	empty UMETA(DisplayName = "empty"),
	occupied  UMETA(DisplayName = "occupied"),
};
UCLASS()
class S5238543PROJECT_API ATileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

};
