// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/GASBaseAnimInstance.h"
#include "GASCharacterAnimInstance.generated.h"

class AGASBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class GAS_API UGASCharacterAnimInstance : public UGASBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	TObjectPtr<AGASBaseCharacter> OwningCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bHasAcceleration;

};
