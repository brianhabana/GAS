// All Rights Reserver River & Rain Productions

#include "AnimInstances/Hero/GASHeroAnimInstance.h"
#include "Characters/GASHeroCharacter.h"

void UGASHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AGASHeroCharacter>(OwningCharacter);
	}
}

void UGASHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		IdleElapsedTime+=DeltaSeconds;
		bShouldEnterRelaxedState = (IdleElapsedTime >= EnterRelaxedStateThreshold);
	}
}
