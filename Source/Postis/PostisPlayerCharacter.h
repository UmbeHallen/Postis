#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PostisPlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathDelegate);

UCLASS(BlueprintType, Blueprintable)
class POSTIS_API APostisPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APostisPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	bool bIsDead = false;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeathDelegate OnDeath;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void CheckDeath();

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintPure, Category = "Health")
	bool IsDead() const { return bIsDead; }

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Health")
	void OnDeathBP();

private:
	void HandleDeath();
};
