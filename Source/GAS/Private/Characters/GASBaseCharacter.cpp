// All Rights Reserved River & Rain Productions


#include "Characters/GASBaseCharacter.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "AbilitySystem/GASAttributeSet.h"

AGASBaseCharacter::AGASBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals;

	GasAbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>(TEXT("GasAbilitySystemComponent"));
	GasAttributeSet = CreateDefaultSubobject<UGASAttributeSet>(TEXT("GasAttributeSet"));
}

UAbilitySystemComponent* AGASBaseCharacter::GetAbilitySystemComponent() const
{
	return GetGasAbilitySystemComponent();
}

void AGASBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(GasAbilitySystemComponent)
	{
		GasAbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
		
}
