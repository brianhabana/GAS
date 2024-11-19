// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GASBaseCharacter.generated.h"

class UGASAbilitySystemComponent;
class UGASAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class GAS_API AGASBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UGASAbilitySystemComponent> GASAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UGASAttributeSet> GASAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartupData;
	
public:
	FORCEINLINE TObjectPtr<UGASAbilitySystemComponent> GetGasAbilitySystemComponent() const { return GASAbilitySystemComponent;}
	FORCEINLINE TObjectPtr<UGASAttributeSet> GetAttributeSet() const { return GASAttributeSet;}
};
