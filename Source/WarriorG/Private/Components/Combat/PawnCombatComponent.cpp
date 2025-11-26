// Ghostory All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"
#include "WarriorDebugHelper.h"
#include "Items/Weapons/WarriorWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponRegister, bool bRegisterAsEquippedWeapon)
{
    checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A named name %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
    check(InWeaponRegister);

    CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponRegister);

    if (bRegisterAsEquippedWeapon)
    {
        // 장착되어있으면,
        CurrentEquippedWeaponTag = InWeaponTagToRegister;
    }
    const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *InWeaponRegister->GetName(), *InWeaponTagToRegister.ToString());
    Debug::Print(WeaponString);
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
    if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
    {
        if (AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
        {
            return *FoundWeapon;
        }
    }
    return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
    if (!CurrentEquippedWeaponTag.IsValid())
    {
        return nullptr;
    }
    return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
