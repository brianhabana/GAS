// All Rights Reserved River & Rain Productions


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/GASWeaponBase.h"
#include "GASDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(
	FGameplayTag InWeaponTagToRegister,
	AGASWeaponBase* InWeaponToRegister,
	bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),
		TEXT("A Named %s has already been added as a carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	//debug msg
	const FString WeaponString = FString::Printf(TEXT("A Weapon named: %s has been regiestered using the tag %s"),
		*InWeaponToRegister->GetName(),
		*InWeaponTagToRegister.ToString());
	Debug::Printf(WeaponString);
}

AGASWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (AGASWeaponBase* const* FoundWeapon =  CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AGASWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return  nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
