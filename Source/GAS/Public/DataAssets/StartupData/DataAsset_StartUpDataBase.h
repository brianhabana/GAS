// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UGASGameplayAbility;
class UGASAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GAS_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(
		TObjectPtr<UGASAbilitySystemComponent> InASCToGive,
		int32 ApplyLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UGASGameplayAbility > > ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UGASGameplayAbility > > ReactiveAbilities;

	void GrantAbilities(
		const TArray< TSubclassOf < UGASGameplayAbility > >& InAbilitiesToGive,
		TObjectPtr<UGASAbilitySystemComponent> InASCToGive,
		int32 ApplyLevel = 1
		);
};
