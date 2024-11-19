// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUpData.generated.h"

USTRUCT(BlueprintType)
struct FGASHeroAbilitySet
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGASGameplayAbility> AbilityToGrant;

	bool IsValid() const;
	
};
/**
 * 
 */
UCLASS()
class GAS_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(
		TObjectPtr<UGASAbilitySystemComponent> InASCToGive,
		int32 ApplyLevel = 1) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FGASHeroAbilitySet> HeroStartUpAbilitiesSets;
};
