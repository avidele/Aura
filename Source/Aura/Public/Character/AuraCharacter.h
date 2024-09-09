// Copyright Avidel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UWidgetComponent;
class UAuraHeroComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:

	
	AAuraCharacter();
	UFUNCTION(BlueprintCallable)
	UAuraHeroComponent* GetCombatComponent() const;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> L_Weapon;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> R_Weapon;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttackEnd();
	
	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */
private:
	virtual void InitAbilityActorInfo() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAuraHeroComponent> HeroComponent;
	
	virtual void InitializeDefaultAttributes() const override;
};
