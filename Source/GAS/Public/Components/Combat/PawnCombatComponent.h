// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AGASWeaponBase;
/**
 * 
 */
UCLASS()
class GAS_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Hero|Combat")
	void RegisterSpawnedWeapon(
		FGameplayTag InWeaponTagToRegister,
		AGASWeaponBase*  InWeaponToRegister,
		bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Hero|Combat")
	AGASWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UFUNCTION(BlueprintCallable, Category = "Hero|Combat")
	AGASWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
	UPROPERTY(BlueprintReadOnly, Category = "Hero|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, AGASWeaponBase* > CharacterCarriedWeaponMap;
};
