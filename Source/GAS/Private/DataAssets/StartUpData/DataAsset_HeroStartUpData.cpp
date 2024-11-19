// All Rights Reserved River & Rain Productions


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/GASGameplayAbility.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"

bool FGASHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(TObjectPtr<UGASAbilitySystemComponent> InASCToGive,
	int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for(const FGASHeroAbilitySet& AbilitySet : HeroStartUpAbilitiesSets)
	{
		if(!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
