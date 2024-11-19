// All Rights Reserved River & Rain Productions


#include "Characters/GASBaseCharacter.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/GASAttributeSet.h"

AGASBaseCharacter::AGASBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals;

	GASAbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>(TEXT("GasAbilitySystemComponent"));
	GASAttributeSet = CreateDefaultSubobject<UGASAttributeSet>(TEXT("GasAttributeSet"));
}

UAbilitySystemComponent* AGASBaseCharacter::GetAbilitySystemComponent() const
{
	return GetGasAbilitySystemComponent();
}

void AGASBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(GASAbilitySystemComponent)
	{
		GASAbilitySystemComponent->InitAbilityActorInfo(this,this);

		ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Forogt to assign start up data to %s"), *GetName());
	}
}
