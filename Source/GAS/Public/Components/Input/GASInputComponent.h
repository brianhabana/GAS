// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "GASInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGASInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(
		const  TObjectPtr<UDataAsset_InputConfig> InInputConfig,
		const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent,
		UserObject* ContextObject,
		CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(
		const  TObjectPtr<UDataAsset_InputConfig> InInputConfig,
		UserObject* ContextObject,
		CallbackFunc InputPressedFunc,
		CallbackFunc InputReleased);
};

template <class UserObject, typename CallbackFunc>
inline void UGASInputComponent::BindNativeInputAction(
	const TObjectPtr<UDataAsset_InputConfig> InInputConfig,
	const FGameplayTag& InInputTag,
	ETriggerEvent TriggerEvent,
	UserObject* ContextObject,
	CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input Config data asset is null, can not proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent, ContextObject, Func);
		
	}
}

template <class UserObject, typename CallbackFunc>
void UGASInputComponent::BindAbilityInputAction(
	const TObjectPtr<UDataAsset_InputConfig> InInputConfig,
	UserObject* ContextObject,
	CallbackFunc InputPressedFunc,
	CallbackFunc InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("Input Config data asset is null, can not proceed with binding"));

	for(const FGASInputActionConfig& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if(!AbilityInputActionConfig.IsValid()) continue;

		BindAction(
			AbilityInputActionConfig.InputAction,
			ETriggerEvent::Started, ContextObject,
			InputPressedFunc,
			AbilityInputActionConfig.InputTag);

		BindAction(
			AbilityInputActionConfig.InputAction,
			ETriggerEvent::Completed, ContextObject,
			InputReleasedFunc,
			AbilityInputActionConfig.InputTag);
	}
}


