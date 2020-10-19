// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingPumpkin.h"

// Sets default values
AFloatingPumpkin::AFloatingPumpkin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    visualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    visualMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (CubeVisualAsset.Succeeded())
    {
        visualMesh->SetStaticMesh(CubeVisualAsset.Object);
        visualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

}

// Called when the game starts or when spawned
void AFloatingPumpkin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingPumpkin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
    float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

