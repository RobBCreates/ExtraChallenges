// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugActorSolution.generated.h"

class URotatingMovementComponent;

UENUM(BlueprintType)
enum ETraceType
{
	TT_World  UMETA(DisplayName = "World"),
	TT_Kismet	UMETA(DisplayName = "Kismet")
};

UCLASS()
class WEEK5_DEBUG_API ADebugActorSolution : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugActorSolution();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	USceneComponent* DefaultRootComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	URotatingMovementComponent* RotatingComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Debug")
	TEnumAsByte<ETraceType> TraceType = ETraceType::TT_World;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Debug")
	float TraceDistance = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Debug")
	bool bShowDebug = true;
	
};
