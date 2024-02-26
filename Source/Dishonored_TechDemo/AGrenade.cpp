// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrenade.h"

// Sets default values
AAGrenade::AAGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAGrenade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

