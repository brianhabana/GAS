// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GASBaseCharacter.generated.h"

class UGASAbilitySystemComponent;
class UGASAttributeSet;
UCLASS()
class GAS_API AGASBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UGASAbilitySystemComponent> GasAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UGASAttributeSet> GasAttributeSet;

public:
	FORCEINLINE TObjectPtr<UGASAbilitySystemComponent> GetGasAbilitySystemComponent() const { return GasAbilitySystemComponent;}
	FORCEINLINE TObjectPtr<UGASAttributeSet> GetAttributeSet() const { return GasAttributeSet;}
};
