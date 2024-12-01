// All Rights Reserved River & Rain Productions

#pragma once

#include "GASStructsType.generated.h"

class UGASHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FGASHeroWeaponData
{
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGASHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};