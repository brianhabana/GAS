// All Rights Reserved River & Rain Productions

#include "Characters/GASHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/GASInputComponent.h"
#include "GASGameplayTags.h"
#include "AbilitySystem/GASAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "GASDebugHelper.h"

AGASHeroCharacter::AGASHeroCharacter()
{
	// Initialize the capsule size for collision detection
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// Disable controller-based rotation for pitch, yaw, and roll
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create and configure the camera boom (spring arm)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent()); 
	CameraBoom->TargetArmLength = 200.f; 
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f); 
	CameraBoom->bUsePawnControlRotation = true;

	// Create and configure the follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false; 

	// Configure character movement settings
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f); 
	GetCharacterMovement()->MaxWalkSpeed = 400.f; 
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; 

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("CombatComponent"));
}

void AGASHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartupData.IsNull())
	{
		if (TObjectPtr<UDataAsset_StartUpDataBase> LoadedData = CharacterStartupData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(GASAbilitySystemComponent);
		}
	}
}

void AGASHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"))
	TObjectPtr<ULocalPlayer> LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem)
	{
		Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0) ;

		TObjectPtr<UGASInputComponent> GASInputComponent = CastChecked<UGASInputComponent>(PlayerInputComponent);

		GASInputComponent->BindNativeInputAction(
			InputConfigDataAsset,
			GASGameplayTags::InputTag_Move,
			ETriggerEvent::Triggered,
			this,
			&ThisClass::Input_Move);

		GASInputComponent->BindNativeInputAction(
			InputConfigDataAsset,
			GASGameplayTags::InputTag_Look,
			ETriggerEvent::Triggered,
			this,
			&ThisClass::Input_Look);

		GASInputComponent->BindAbilityInputAction(
			InputConfigDataAsset,
			 this,
			 &ThisClass::Input_AbilityInputPressed,
			 &ThisClass::Input_AbilityInputReleased);
	}
}

void AGASHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGASHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2d>();
	const FRotator MovementRotation(0.f,Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector((FVector::ForwardVector));

		AddMovementInput(ForwardDirection, MovementVector.Y);
		
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector((FVector::RightVector));

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGASHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2d LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGASHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	GASAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AGASHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	GASAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
