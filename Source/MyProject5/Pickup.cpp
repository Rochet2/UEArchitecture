// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // All pickups start active
    bIsActive = true;

    // Create the static mesh component
    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
    UStaticMesh* Asset = MeshAsset.Object;
    PickupMesh->SetStaticMesh(Asset);
    RootComponent = PickupMesh;
}

// Returns active state
bool APickup::IsActive()
{
    return bIsActive;
}

// Sets active state
void APickup::SetActive(bool NewPickupState)
{
    bIsActive = NewPickupState;
}

void APickup::WasCollected_Implementation()
{
    FString PickupDebugString = GetName();
    UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

