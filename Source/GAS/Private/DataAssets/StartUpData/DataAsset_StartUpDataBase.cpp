// All Rights Reserved River & Rain Productions

#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/GASGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(TObjectPtr<UGASAbilitySystemComponent> InGasASCToGive,
	int32 ApplyLevel)
{
	check(InGasASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InGasASCToGive, ApplyLevel);
	GrantAbilities(ActivateOnGivenAbilities, InGasASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UGASGameplayAbility>>& InAbilitiesToGive,
	TObjectPtr<UGASAbilitySystemComponent> InGasASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for(const TSubclassOf<UGASGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);

		AbilitySpec.SourceObject = InGasASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InGasASCToGive->GiveAbility(AbilitySpec);
	}
}
