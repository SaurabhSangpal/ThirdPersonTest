// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBehavior.generated.h"

class AActor;
class UCharacterMovementComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THIRDPERSON_API UPlayerBehavior : public UActorComponent {
    GENERATED_BODY()

   public:
    // Sets default values for this component's properties
    UPlayerBehavior();

   protected:
    // Called when the game starts
    virtual void BeginPlay() override;

   public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;

   private:
    void SetGravityScaleToNormal();
    void SetGravityScaleToFalling();

   public:
    // Multiplier to gravity value when the actor isn't falling
    UPROPERTY(EditAnywhere)
    float NormalGravityScale;
    // Multiplier to gravity value when the actor is falling
    UPROPERTY(EditAnywhere)
    float FallingGravityScale;

   private:
    AActor*                      MyActor;
    UCharacterMovementComponent* MyCharacterMovement;
};
