// Copyright River & Rain

#include "Characters/GASHeroCharacter.h"
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
	CameraBoom->SetupAttachment(GetRootComponent()); // Attach camera boom to root component
	CameraBoom->TargetArmLength = 200.f; // Set the camera boom distance from the character
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f); // Set an offset for the camera position
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on controller input

	// Create and configure the follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach camera to end of camera boom
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate based on controller

	// Configure character movement settings
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f); // Configure the character's rotation speed
	GetCharacterMovement()->MaxWalkSpeed = 400.f; // Configure the character's walking speed
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // Configure the deceleration when the character stops
}

void AGASHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Printf(TEXT("Working!"));
}
