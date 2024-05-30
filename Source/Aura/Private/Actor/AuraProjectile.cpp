#include "Actor/AuraProjectile.h"

#include "AbilitySystemComponent.h"
#include "Character/AuraCharacterBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

class AAuraCharacterBase;

AAuraProjectile::AAuraProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 1000.f;
	ProjectileMovementComponent->MaxSpeed = 1000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
}

void AAuraProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraProjectile::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.
	AAuraCharacterBase* AuraCharacterBase = Cast<AAuraCharacterBase>(OtherActor);
	UAbilitySystemComponent* ASC = AuraCharacterBase->GetAbilitySystemComponent();
	FGameplayEffectContextHandle GameplayEffectContextHandle = ASC->MakeEffectContext();
	FGameplayEffectSpecHandle DamageEffectSpecHandle = ASC->MakeOutgoingSpec(DamageGameplayEffect, Level, GameplayEffectContextHandle);
	ASC->ApplyGameplayEffectSpecToTarget(*DamageEffectSpecHandle.Data.Get(), ASC);
}
