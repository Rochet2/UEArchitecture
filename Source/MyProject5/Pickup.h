// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class MYPROJECT5_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

    /** Return the mesh for the pickup */
    FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

    /** Return whether or not the pickup is active */
    UFUNCTION(BlueprintPure, Category = "Pickup")
    bool IsActive();

    /** Allows other classes to safely change pickup activeness  */
    UFUNCTION(BlueprintCallable, Category = "Pickup")
    void SetActive(bool NewPickupState);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pickup")
    void WasCollected();
    virtual void WasCollected_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    /** True when the pickup can be used and false when it is deactivated */
    bool bIsActive;

private:	
    /** Static mesh to represent the pickup in the level */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent* PickupMesh;
	
};
