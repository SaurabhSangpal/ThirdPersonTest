// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBehavior.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UPlayerBehavior::UPlayerBehavior() {
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You
    // can turn these features off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    NormalGravityScale  = 1.0f;
    FallingGravityScale = 1.0f;
}

// Called when the game starts
void UPlayerBehavior::BeginPlay() {
    Super::BeginPlay();

    MyActor = GetOwner();
    check(MyActor != nullptr);
    MyCharacterMovement = MyActor->FindComponentByClass<UCharacterMovementComponent>();
    check(MyCharacterMovement != nullptr);
}

// Called every frame
void UPlayerBehavior::TickComponent(float DeltaTime, ELevelTick TickType,
                                    FActorComponentTickFunction* ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    auto Velocity = MyActor->GetVelocity();
    if (Velocity.Z >= 0) {
        SetGravityScaleToNormal();
    } else {
        SetGravityScaleToFalling();
    }
}

void UPlayerBehavior::SetGravityScaleToNormal() {
    if (MyCharacterMovement->GravityScale != NormalGravityScale) {
        MyCharacterMovement->GravityScale = NormalGravityScale;
    }
}

void UPlayerBehavior::SetGravityScaleToFalling() {
    if (MyCharacterMovement->GravityScale != FallingGravityScale) {
        MyCharacterMovement->GravityScale = FallingGravityScale;
    }
}
