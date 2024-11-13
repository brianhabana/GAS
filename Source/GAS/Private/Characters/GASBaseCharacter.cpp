// Copyright River & Rain


#include "Characters/GASBaseCharacter.h"

AGASBaseCharacter::AGASBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals;
}
