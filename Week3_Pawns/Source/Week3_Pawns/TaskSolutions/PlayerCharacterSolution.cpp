// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterSolution.h"

// Sets default values
APlayerCharacterSolution::APlayerCharacterSolution()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacterSolution::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterSolution::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacterSolution::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Below we create Input Bindings to both Axis and Actions to call specific functions when the assigned button is pressed. 
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump); // Note this is bound to a function on &ACharacter not our APlayerCharacterComplete because the Character class already has
	// functionality built in for jumping and we can use that on IE_Pressed. 
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping); // Note this is bound to a function on &ACharacter not our APlayerCharacterComplete because the Character class already has
	// functionality built in for jumping. Here we're calling StopJumping on IE_Released (When the button is released), this is because we're also tracking things like jump counts and jump heights and we need to tell the system
	// the current jump has been ended. 

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacterSolution::MoveForward); // Axis binding calling the custom MoveForward function in our &APlayerCharacterComponent class.
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacterSolution::MoveRight); // Axis binding calling the custom MoveRight function in our &APlayerCharacterComponent class.
}

void APlayerCharacterSolution::MoveForward(float Value)
{
	// 
	if(Controller && (Value!= 0.0f))
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerCharacterSolution::MoveRight(float Value)
{
	if(Controller && (Value!= 0.0f))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

