// All Rights Reserver River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/GASBaseAnimInstance.h"
#include "GASHeroLinkedAnimLayer.generated.h"

class UGASHeroAnimInstance;

/**
 * 
 */
UCLASS()
class GAS_API UGASHeroLinkedAnimLayer : public UGASBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UGASHeroAnimInstance* GetHeroAnimInstance() const;
};
