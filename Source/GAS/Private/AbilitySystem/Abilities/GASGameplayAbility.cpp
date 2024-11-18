// All Rights Reserved River & Rain Productions

#include "AbilitySystem/Abilities/GASGameplayAbility.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "Components/combat/PawnCombatComponent.h"

void UGASGameplayAbility::OnGiveAbility(
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EGasAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UGASGameplayAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if(AbilityActivationPolicy == EGasAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{	
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
	
}

UPawnCombatComponent* UGASGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}
