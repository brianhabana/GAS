// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GASGameplayAbility.h"
#include "GASHeroGameplayAbility.generated.h"

/**
 * 
 */

class AGASHeroCharacter;
class AGASHeroController;

UCLASS()
class GAS_API UGASHeroGameplayAbility : public UGASGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AGASHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AGASHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
		
private:
	TWeakObjectPtr<AGASHeroCharacter> CachedGASHeroCharacter;
	TWeakObjectPtr<AGASHeroController> CachedGASHeroController;
};
