// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnJumpSolution.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerPawnJumpSolution::APlayerPawnJumpSolution()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Comp"));
	RootComponent = CapsuleComponent;
	CapsuleComponent->SetSimulatePhysics(true);

	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	PlayerMesh->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(PlayerMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent);

	CapsuleComponent->OnComponentHit.AddDynamic(this, &APlayerPawnJumpSolution::OnHit);
}

// Called when the game starts or when spawned
void APlayerPawnJumpSolution::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawnJumpSolution::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

// Called to bind functionality to input
void APlayerPawnJumpSolution::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerPawnJumpSolution::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawnJumpSolution::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawnJumpSolution::MoveRight);
}

void APlayerPawnJumpSolution::Move()
{
	AddActorWorldOffset(FVector(Forward, Right, 0));
}

void APlayerPawnJumpSolution::Jump()
{
	// Cap the number of jumps we can make. 
	if(JumpCount >= MaxJumpCount) { return; }
	// Apply an impulse to the Mesh in the Z Axis.
	CapsuleComponent->AddImpulse(FVector(0,0, JumpForce),"", true);
	// Track how many times we've jumped. 
	JumpCount++;
}

void APlayerPawnJumpSolution::MoveForward(float Value)
{
	Forward = Value * MovementSpeed * GetWorld()->DeltaTimeSeconds;
}

void APlayerPawnJumpSolution::MoveRight(float Value)
{
	Right = Value * MovementSpeed * GetWorld()->DeltaTimeSeconds;
}

void APlayerPawnJumpSolution::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Get Direction we hit the surface on the Z axis. 
	const float HitDirection = Hit.Normal.Z;
	
	// If it's more than 0 then we've hit something below us. 1 is flat, anything between is a slope or at least hitting us from the side.
	// Less than 0 to -1 means we're being hit from the side up to the top of the player "head". 
	if(HitDirection > 0)
	{
		JumpCount = 0;
	}
}


