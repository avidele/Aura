// Copyright Avidel


#include "AbilitySystem/MMC/EEC_DamageExecCalculation.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

struct GDDamegeStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Strength);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Armor);

	GDDamegeStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet, Strength, Source, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UAuraAttributeSet, Armor, Target, false);
	}
};

static const GDDamegeStatics& DamageStatics()
{
	static GDDamegeStatics DStatics;
	return DStatics;
}

UEEC_DamageExecCalculation::UEEC_DamageExecCalculation()
{
	RelevantAttributesToCapture.Add(DamageStatics().StrengthDef);
	RelevantAttributesToCapture.Add(DamageStatics().ArmorDef);
}

void UEEC_DamageExecCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                                        FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);
	UAbilitySystemComponent* TargetAbilitySystem = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystem = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceAbilitySystem ? SourceAbilitySystem->GetAvatarActor() : nullptr;
	AActor* TargetActor = TargetAbilitySystem ? TargetAbilitySystem->GetAvatarActor() : nullptr;

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float Armor = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ArmorDef, EvaluateParameters, Armor);
	Armor = FMath::Max<float>(Armor, 0.0f);

	float Damage = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().StrengthDef, EvaluateParameters, Damage);
	//Damage = FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Attributes.Primary.Strength")), false,0.f), 0.0f);
	Damage = FMath::Max<float>(Damage, 0.0f);
	const float UnmitigatedDamage = Damage;
	const float MitigatedDamage = (UnmitigatedDamage) * (100 / (100 + Armor));
	if (MitigatedDamage > 0)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().StrengthProperty, EGameplayModOp::Additive, MitigatedDamage));
	}
	if (UAuraAbilitySystemComponent* TargetAuraAbilitySystem = Cast<UAuraAbilitySystemComponent>(TargetAbilitySystem))
	{
		UAuraAbilitySystemComponent *SourceAuraAbilitySystem = Cast<UAuraAbilitySystemComponent>(SourceAbilitySystem);
		TargetAuraAbilitySystem->ReceiveDamage(SourceAuraAbilitySystem, UnmitigatedDamage, MitigatedDamage);
	}
}
