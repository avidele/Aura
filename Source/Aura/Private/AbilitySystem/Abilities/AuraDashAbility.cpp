// Copyright Avidel


#include "AbilitySystem/Abilities/AuraDashAbility.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/Abilities/AuraCyberCombo.h"
#include "Character/AuraCharacter.h"
#include "Character/AuraHeroComponent.h"

/*
 * In Unreal Engine's Gameplay Ability System, when an ability is activated on the client,
 * it sends a request to the server to also activate the ability.
 * This ensures that the ability's effects are replicated and synchronized across the network.
 * The server validates the request and then executes the ability, which can include applying effects,
 * playing animations, and more. This mechanism ensures consistency and prevents cheating.
 */
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
