// All Rights Reserved River & Rain Productions


#include "AbilitySystem/GASAbilitySystemComponent.h"

void UGASAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}
	
	for( const FGameplayAbilitySpec& AbilitySpec :GetActivatableAbilities())
	{
		if(!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;
		
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UGASAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
