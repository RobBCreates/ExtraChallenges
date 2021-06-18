// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalingCubeSolution.generated.h"

UCLASS()
class WEEK2_TRANSFORMS_API AScalingCubeSolution : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScalingCubeSolution();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* Mesh;

	// Speed to scale the Actor. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default. 
	float ScalingRate = 0.1f;

	// How many seconds between switching rotation direction. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true"))
	float TimeBetweenSwitch = 5.0f; 

	// Variable to be tracked in the EventTick.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true"))
	float CurrentTime = 0.0f; 

	// We need an additional float in this mechanic to track the scale of the cube as well as the time as there's no Offset function,
	// so we'll be adding/subtracting scale manually. 
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true"))
	float CurrentScale = 1.0f; // Defaulting the value to ZERO as we don't want the cube to start at (0,0,0) when we plugin this in. 
};
