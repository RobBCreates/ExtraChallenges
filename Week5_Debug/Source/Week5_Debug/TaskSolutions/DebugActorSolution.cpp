// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugActorSolution.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White,String)

// Sets default values
ADebugActorSolution::ADebugActorSolution()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = DefaultRootComponent;
	
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rotating Component"));
	
}

// Called when the game starts or when spawned
void ADebugActorSolution::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADebugActorSolution::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Start = GetActorLocation();
	const FVector End = ((GetActorForwardVector() * TraceDistance) + Start);
	FHitResult Hit;
	
	if(TraceType == ETraceType::TT_World)
	{
		FCollisionQueryParams TraceParams;
		bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

		if(bShowDebug)
		{
			DrawDebugLine(GetWorld(), Start, bHit ? Hit.Location : End, FColor::White, false, 3.0f);
		}
		if(bHit && bShowDebug)
		{
			DrawDebugSphere(GetWorld(), Hit.Location, 3.0f, 12, FColor::Orange, false, 3.0f);
			PrintString(FString::Printf(TEXT("Trace Hit: %s"), *Hit.GetActor()->GetName()));
		}
	}
	else
	{
		const TArray<AActor*> ActorsToIgnore;
		const bool bHit = UKismetSystemLibrary::LineTraceSingle(this, Start, End,
			UEngineTypes::ConvertToTraceType(ECC_Camera),
			false, ActorsToIgnore, bShowDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hit, true,
			FLinearColor::Yellow, FLinearColor::White, 3.0f);

		if(bHit && bShowDebug)
		{
			PrintString(FString::Printf(TEXT("Trace Hit: %s"), *Hit.GetActor()->GetName()));
		}
	}	
}

