// Copyright Avidel


#include "Character/AuraHeroComponent.h"

#include "AbilitySystemComponent.h"
#include "Character/AuraCharacterBase.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"

void UAuraHeroComponent::ClientAttack()
{
	const auto PlayerState = Cast<AAuraPlayerState>(GetOwner());
	const auto OwnerPawn = Cast<AAuraPlayerController>(PlayerState->GetOwner())->GetPawn();
	const auto OwnerCharacter = Cast<ACharacter>(OwnerPawn);
	if (!AttackMontage || !OwnerCharacter) return;
	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("Client Attack"));
	}
	else if (GetOwnerRole() == ROLE_Authority)
	{
		if (CurrentState != ECombat_State::Attack)
		{
			ChangeCombatState(ECombat_State::Attack);
			bWantContinueAttack = false;
			CurrentAttackMontageSection = 0;
			MakeAttackAdsorption();
			OwnerCharacter->PlayAnimMontage(AttackMontage, 2.f,
			                                AttackMontage->GetSectionName(CurrentAttackMontageSection));
		}
		else if (CurrentState == ECombat_State::Attack && CurrentAttackMontageSection < AttackMontage->GetNumSections()
			- 1)
		{
			bWantContinueAttack = true;
		}
	}
	else if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		OwnerCharacter->PlayAnimMontage(AttackMontage, 2.f, AttackMontage->GetSectionName(CurrentAttackMontageSection));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("SimulatedProxy Attack"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("No Role"));
	}
}


bool UAuraHeroComponent::ChangeCombatState(F_Combat_State NextState)
{
	CurrentState = NextState;
	return true;
}

void UAuraHeroComponent::AttackEnd()
{
	const auto PlayerState = Cast<AAuraPlayerState>(GetOwner());
	const auto OwnerPawn = Cast<AAuraPlayerController>(PlayerState->GetOwner())->GetPawn();
	if (const auto OwnerCharacter = Cast<ACharacter>(OwnerPawn); OwnerCharacter && bWantContinueAttack)
	{
		bWantContinueAttack = false;
		if (CurrentAttackMontageSection == AttackMontage->GetNumSections() - 1)
		{
			ChangeCombatState(ECombat_State::Idle);
			CurrentAttackMontageSection = 0;
			return;
		}
		CurrentAttackMontageSection += 1;
		FString Msg = FString::Printf(
			TEXT("Section: %s"), *(AttackMontage->GetSectionName(CurrentAttackMontageSection).ToString()));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, Msg
		);
		MakeAttackAdsorption();
		OwnerCharacter->PlayAnimMontage(AttackMontage, 2.f, AttackMontage->GetSectionName(CurrentAttackMontageSection));
	}
	else if (!bWantContinueAttack)
	{
		ChangeCombatState(ECombat_State::Idle);
	}
}

void UAuraHeroComponent::MakeAttackAdsorption() const
{
	const auto PlayerState = Cast<AAuraPlayerState>(GetOwner());
	const auto OwnerPawn = Cast<AAuraPlayerController>(PlayerState->GetOwner())->GetPawn();
	if (const auto OwnerCharacter = Cast<ACharacter>(OwnerPawn))
	{
		const FVector Start = OwnerCharacter->GetActorLocation();
		TArray<FHitResult> HitResults;
		FCollisionQueryParams CollisionQueryParams;
		CollisionQueryParams.AddIgnoredActor(OwnerCharacter);

		if (constexpr float Radius = 1000.f;
			GetWorld()->SweepMultiByChannel(HitResults, Start, Start, FQuat::Identity,
			                                ECollisionChannel::ECC_WorldDynamic, FCollisionShape::MakeSphere(Radius),
			                                CollisionQueryParams))
		{
			//Debug Line
			if (bUseDebug)
			{
				DrawDebugSphere(GetWorld(), Start, Radius, 12, FColor::Red, false, 5.f);
			}
			const FHitResult* NearestHitResult = nullptr;
			float NearestDistance = FLT_MAX;
			for (FHitResult& HitResult : HitResults)
			{
				if (const float Distance = (HitResult.ImpactPoint - Start).Size(); Distance < NearestDistance &&
					HitResult.GetActor()->ActorHasTag(FName("Enemy")))
				{
					NearestDistance = Distance;
					NearestHitResult = &HitResult;
				}
			}
			if (NearestHitResult)
			{
				const FVector HitLocation = NearestHitResult->ImpactPoint;
				const FRotator TargetRotator = UKismetMathLibrary::FindLookAtRotation(
					OwnerCharacter->GetActorLocation(), HitLocation);
				if (bUseDebug)
				{
					DrawDebugLine(GetWorld(), Start, HitLocation, FColor::Green, false, 5.f);
				}
				const FRotator CurrentRotator = OwnerCharacter->GetActorRotation();
				const FRotator NewRotator = FRotator(CurrentRotator.Pitch, TargetRotator.Yaw, CurrentRotator.Roll);
				OwnerCharacter->SetActorRotation(NewRotator);
			}
		}
	}
}
