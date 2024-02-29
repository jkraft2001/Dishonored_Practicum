// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrenade.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AAGrenade::AAGrenade()
{
	TimerCountdown = 4.0f;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetupAttachment(MeshComp);

	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComp->SetupAttachment(MeshComp);

	ForceComp->SetAutoActivate(false);

	ForceComp->Radius = 500.0f;
	ForceComp->ImpulseStrength = 800.0f;
	ForceComp->bImpulseVelChange = true;

	ForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);

	// Binding either here or in PostInitializeComponent() below
	// MeshComp->OnComponentHit.AddDynamic(this, &AAGrenade::OnActorHit;

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

void AAGrenade::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	MeshComp->OnComponentHit.AddDynamic(this, &AAGrenade::OnActorHit);

}

void AAGrenade::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComp->FireImpulse();

	/*
	UE_LOG(LogTemp, Log, TEXT("OnActorHit an Explosive Barrel"));

	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	//DrawDebugSphere(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
	*/

}


