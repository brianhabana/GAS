// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class GAS_API AGASWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGASWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;

public:
	FORCEINLINE TObjectPtr<UBoxComponent> GetWeaponCollisionBox() const {return WeaponCollisionBox;};

};
