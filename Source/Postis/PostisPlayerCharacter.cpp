#include "PostisPlayerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APostisPlayerCharacter::APostisPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentHealth = MaxHealth;
}

void APostisPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentHealth = MaxHealth;
	bIsDead = false;
}

void APostisPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APostisPlayerCharacter::Jump()
{
	Super::Jump();
	
	// Fire primary action when jumping
	FirePrimaryAction();
}

void APostisPlayerCharacter::FirePrimaryAction()
{
	if (bIsDead)
	{
		return;
	}

	// Call Blueprint implementable event for custom behavior
	OnFirePrimaryActionBP();
}

void APostisPlayerCharacter::TakeDamage(float DamageAmount)
{
	if (bIsDead)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.0f, MaxHealth);
	
	CheckDeath();
}

void APostisPlayerCharacter::CheckDeath()
{
	if (CurrentHealth <= 0.0f && !bIsDead)
	{
		HandleDeath();
	}
}

void APostisPlayerCharacter::HandleDeath()
{
	bIsDead = true;
	
	// Broadcast the death event
	OnDeath.Broadcast();
	
	// Call Blueprint implementable event
	OnDeathBP();
	
	// Optional: Disable input
	DisableInput(nullptr);
}
