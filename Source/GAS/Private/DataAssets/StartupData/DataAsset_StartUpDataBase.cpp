// All Rights Reserved River & Rain Productions


#include "DataAssets/StartupData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/GASGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UGASAbilitySystemComponent* InGasASCToGive,
	int32 ApplyLevel)
{
	check(InGasASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InGasASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InGasASCToGive, ApplyLevel);	

}

void UDataAsset_StartUpDataBase::GrantAbilities(
	const TArray<TSubclassOf<UGASGameplayAbility>>& InAbilitiesToGive,
	UGASAbilitySystemComponent* InGasASCToGive,
	int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for(const TSubclassOf<UGASGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if(!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InGasASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InGasASCToGive->GiveAbility(AbilitySpec);
	}
}
