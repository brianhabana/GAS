// All Rights Reserved River & Rain Productions

#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/GASGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(TObjectPtr<UGASAbilitySystemComponent> InASCToGive,
	int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(
	const TArray<TSubclassOf<UGASGameplayAbility>>& InAbilitiesToGive,
	TObjectPtr<UGASAbilitySystemComponent> InASCToGive, 
	int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for(const TSubclassOf<UGASGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
