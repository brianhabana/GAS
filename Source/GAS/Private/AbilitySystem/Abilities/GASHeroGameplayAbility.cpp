// All Rights Reserved River & Rain Productions


#include "AbilitySystem/Abilities/GASHeroGameplayAbility.h"
#include "Characters/GASHeroCharacter.h"
#include "Controllers/GASHeroController.h"
#include "Components/Combat/HeroCombatComponent.h"

AGASHeroCharacter* UGASHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedGASHeroCharacter.IsValid())
	{
		CachedGASHeroCharacter = Cast<AGASHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedGASHeroCharacter.IsValid()? CachedGASHeroCharacter.Get() : nullptr;
}

AGASHeroController* UGASHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if(!CachedGASHeroController.IsValid())
	{
		CachedGASHeroController = Cast<AGASHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedGASHeroController.IsValid()? CachedGASHeroController.Get() : nullptr;
}

UHeroCombatComponent* UGASHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
