// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/GASWeaponBase.h"
#include "GASTypes/GASStructsType.h"
#include "GASHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API AGASHeroWeapon : public AGASWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FGASHeroWeaponData HeroWeaponData;
};
