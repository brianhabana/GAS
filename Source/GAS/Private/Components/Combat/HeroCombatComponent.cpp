// All Rights Reserved River & Rain Productions


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/GASHeroWeapon.h"

AGASHeroWeapon* UHeroCombatComponent::GetHeroCarriedByWeaponTag(FGameplayTag InWeaponTag) const
{
	return Cast<AGASHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
