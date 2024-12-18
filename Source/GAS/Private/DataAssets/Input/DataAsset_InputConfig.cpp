// All Rights Reserved River & Rain Productions


#include "DataAssets/Input/DataAsset_InputConfig.h"

TObjectPtr<UInputAction> UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for(const FGASInputActionConfig& InputActionConfig : NativeInputAction)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
