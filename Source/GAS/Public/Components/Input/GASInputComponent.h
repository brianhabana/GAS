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
