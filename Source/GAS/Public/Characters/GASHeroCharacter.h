// Copyright River & Rain

#pragma once

#include "CoreMinimal.h"
#include "Characters/GASBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GASHeroCharacter.generated.h"

/**
 * 
 */
class USpringArmComponent; 
class UCameraComponent;

UCLASS()
class GAS_API AGASHeroCharacter : public AGASBaseCharacter
{
	GENERATED_BODY()

public:
	AGASHeroCharacter();
	
protected:
	virtual void BeginPlay() override;

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;
	
#pragma endregion

};