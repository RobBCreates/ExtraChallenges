// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawnJumpSolution.generated.h"

UCLASS()
class WEEK4_JUMP_API APlayerPawnJumpSolution : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawnJumpSolution();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* PlayerMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UCameraComponent* Camera;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:

	// Speed the Pawn can move. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default. 
	float MovementSpeed = 400.0f;
	// Max number of times we want to allow the player to jump, allows us to account for double jumps etc. 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default. 
	int32 MaxJumpCount = 1; 
	// Jump force to apply to make the player jump. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables", meta = (AllowPrivateAccess = "true")) // Private specifier added as we can't make something Blueprint Read/Writeable in the Private section by default.
	float JumpForce = 500.0f;
	
	int32 JumpCount = 0; // Tracked number of jumps taken to avoid infinite player jumps.
	bool bGrounded = false; // Not used in this class but provided as an example of how it might be tracked.
	void Move();
	void Jump();

	void MoveForward(float Value);
	void MoveRight(float Value);
	
	// Custom function we'll create to bind to the buWilt in hit function. 
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	float Forward = 0.0f;
	float Right = 0.0f;
};


