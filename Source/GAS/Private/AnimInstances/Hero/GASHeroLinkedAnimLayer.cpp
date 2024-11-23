// All Rights Reserver River & Rain Productions


#include "AnimInstances/Hero/GASHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/GASHeroAnimInstance.h"


UGASHeroAnimInstance* UGASHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UGASHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
