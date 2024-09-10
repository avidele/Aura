// Copyright Avidel


#include "AbilitySystem/Abilities/AuraCyberCombo.h"

#include "Character/AuraCharacter.h"
#include "Character/AuraHeroComponent.h"
#include "GameFramework/Character.h"

void UAuraCyberCombo::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo,
                                      const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (const AAuraCharacter* AvatarActor = Cast<AAuraCharacter>(GetAvatarActorFromActorInfo());
		auto CanCommit = CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		FGameplayEffectSpecHandle DamageEffectSpecHandle = MakeOutgoingGameplayEffectSpec(DamageGameplayEffect, GetAbilityLevel());
		//	DamageEffectSpecHandle.Data.Get()->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Attribute_Primary_Strength"),true), Damage);
		AvatarActor->DamageEffectSpecHandle = DamageEffectSpecHandle;
		UAuraHeroComponent* AuraHeroComponent = AvatarActor->GetCombatComponent();
		AuraHeroComponent->ClientAttack();
	}
	CommitAbilityCooldown(Handle, ActorInfo, ActivationInfo, true);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
}

