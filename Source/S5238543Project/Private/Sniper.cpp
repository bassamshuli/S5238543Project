// Fill out your copyright notice in the Description page of Project Settings.


#include "Sniper.h"

// Sets default values
ASniper::ASniper()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASniper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASniper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASniper::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

