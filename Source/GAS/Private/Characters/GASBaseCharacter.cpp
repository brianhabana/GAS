// All Rights Reserved River & Rain Productions


#include "Characters/GASBaseCharacter.h"

AGASBaseCharacter::AGASBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals;
}
