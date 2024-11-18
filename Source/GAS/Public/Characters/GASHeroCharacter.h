// All Rights Reserved River & Rain Productions

#pragma once

#include "CoreMinimal.h"
#include "Characters/GASBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GASHeroCharacter.generated.h"

struct FInputActionValue;
/**
 * 
 */
class USpringArmComponent; 
class UCameraComponent;
class UDataAsset_InputConfig;
struct UInputActionValue;
class UHeroCombatComponent;

UCLASS()
class GAS_API AGASHeroCharacter : public AGASBaseCharacter
{
	GENERATED_BODY()

public:
	AGASHeroCharacter();
	
protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
	
#pragma endregion

#pragma region Inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

public:
	FORCEINLINE TObjectPtr<UHeroCombatComponent>  GetHeroCombatComponent() const {return HeroCombatComponent;}
};