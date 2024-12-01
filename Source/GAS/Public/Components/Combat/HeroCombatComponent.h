// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Hero|Combat")
	AGASHeroWeapon* GetHeroCarriedByWeaponTag (FGameplayTag InWeaponTag) const;
};
