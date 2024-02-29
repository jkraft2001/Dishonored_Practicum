// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGrenade.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;
class USphereComponent;

UCLASS()
class DISHONORED_TECHDEMO_API AAGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGrenade();

protected:
	float TimerCountdown;

	FTimerHandle TimerHandle_TimerCountdown;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(BlueprintReadOnly)
	URadialForceComponent* ForceComp;

	UPROPERTY(BlueprintReadOnly)
	USphereComponent* SphereComp;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
