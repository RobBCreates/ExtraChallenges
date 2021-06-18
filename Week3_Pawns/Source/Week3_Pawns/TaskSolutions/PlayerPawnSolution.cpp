// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnSolution.h"

// Sets default values
APlayerPawnSolution::APlayerPawnSolution()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawnSolution::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawnSolution::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Inline If statement. Could be something interesting to look into if you've not seen them used before.
	// This bool will be toggled in the Pawn class Blueprint. 
	bUseMovementTypeOne ? MovementTypeOne() : MovementTypeTwo(); 

	// Standard way to implement and If statement, not too exciting. Bool still toggled in Pawn Blueprint. 
	// if(bUseMovementTypeOne)
	// {
	// 	MovementTypeOne();
	// }
	// else
	// {
	// 	MovementTypeTwo();
	// }
		
	// Easier way to call them is to comment one out at a time and compile, this is long and annoying though. 
	// MovementTypeOne();
	// MovementTypeTwo();
}

// Called to bind functionality to input
void APlayerPawnSolution::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawnSolution::MovementTypeOne()
{
	AddActorWorldOffset(ConsumeMovementInputVector());

	AddMovementInput(GetActorForwardVector() * MovementSpeed * GetInputAxisValue("MoveForward") * GetWorld()->DeltaTimeSeconds);
	AddMovementInput(GetActorRightVector() * MovementSpeed * GetInputAxisValue("MoveRight") *GetWorld()->DeltaTimeSeconds);
	
	// Just so we can see which type of move function is being used as it shouldn't feel any different to control.
	UE_LOG(LogTemp, Warning, TEXT("MoveTypeOne"));
}

void APlayerPawnSolution::MovementTypeTwo()
{
	const float Forward = GetInputAxisValue("MoveForward") * MovementSpeed * GetWorld()->DeltaTimeSeconds;
	const float Right = GetInputAxisValue("MoveRight") * MovementSpeed * GetWorld()->DeltaTimeSeconds;
	
	AddActorWorldOffset(FVector(Forward, Right, 0));

	// Just so we can see which type of move function is being used as it shouldn't feel any different to control.
	UE_LOG(LogTemp, Warning, TEXT("MoveTypeTwo"));
}

