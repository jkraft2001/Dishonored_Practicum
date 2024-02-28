// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGrenade.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;

UCLASS()
class DISHONORED_TECHDEMO_API AAGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(BlueprintReadOnly)
	URadialForceComponent* ForceComp;

	virtual void PostInitializeComponents() override;

	//virtual void FireImpulse();

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
