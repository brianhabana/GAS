// All Rights Reserved River & Rain Productions


#include "AnimInstances/GASCharacterAnimInstance.h"
#include "Characters/GASBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UGASCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AGASBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UGASCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed =OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()> 0.f;
}
