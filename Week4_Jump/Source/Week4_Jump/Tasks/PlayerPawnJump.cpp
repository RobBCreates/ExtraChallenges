// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnJump.h"

// Sets default values
APlayerPawnJump::APlayerPawnJump()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawnJump::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawnJump::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawnJump::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

