// Copyright Avidel


#include "AbilitySystem/Abilities/AuraDashAbility.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AuraCyberCombo.h"
#include "Character/AuraCharacter.h"
#include "Character/AuraHeroComponent.h"

void UAuraDashAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                       const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                       const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	if (const AAuraCharacter* AvatarActor = Cast<AAuraCharacter>(GetAvatarActorFromActorInfo()))
	{
		UAuraHeroComponent* AuraHeroComponent = AvatarActor->GetCombatComponent();
		AuraHeroComponent->AttackEnd();
	}
}
