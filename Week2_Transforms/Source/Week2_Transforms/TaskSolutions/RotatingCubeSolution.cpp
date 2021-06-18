// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingCubeSolution.h"

// Sets default values
ARotatingCubeSolution::ARotatingCubeSolution()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Mesh, ensure the component declared in the header is added to the class. 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	// Make the mesh the RootComponent. Other components you add will be placed on this by default. 
	RootComponent = Mesh; 
}

// Called when the game starts or when spawned
void ARotatingCubeSolution::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingCubeSolution::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime+=DeltaTime;

	// -- Two examples of the same result -- // 
	AddActorLocalRotation(FRotator(0,DeltaTime * RotationRate,0)); // Single line example

	// Spread across three lines but more explicit and easier to see what is being affected.
	//FRotator DeltaRotation(0,0,0); 
	//DeltaRotation.Yaw = DeltaTime * RotationRate; 
	//AddActorLocalRotation(DeltaRotation);
	
	if(CurrentTime >= TimeBetweenSwitch)
	{
		CurrentTime = 0;
		RotationRate *= -1;
	}
}

