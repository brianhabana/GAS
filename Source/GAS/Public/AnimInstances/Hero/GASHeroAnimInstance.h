// All Rights Reserver River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/GASCharacterAnimInstance.h"
#include "GASHeroAnimInstance.generated.h"

class AGASHeroCharacter;
/**
 * 
 */
UCLASS()
class GAS_API UGASHeroAnimInstance : public UGASCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category ="AnimData|References")
	TObjectPtr<AGASHeroCharacter> OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category ="AnimData|Locomotion")
	bool bShouldEnterRelaxedState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category ="AnimData|Locomotion")
	float EnterRelaxedStateThreshold = 5.f;

	float IdleElapsedTime;
};
