// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GASGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EGasAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class GAS_API UGASGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;
	
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "HeroAbility")
	EGasAbilityActivationPolicy AbilityActivationPolicy = EGasAbilityActivationPolicy::OnTriggered;
};

