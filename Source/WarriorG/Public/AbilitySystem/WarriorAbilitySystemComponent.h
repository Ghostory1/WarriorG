// Ghostory All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORG_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);
};
