#include "Mage.h"

#include <iostream>

Mage::Mage(FString name, int32 maxHealth, int32 maxDamage, int32 abilityTokens)
: BaseCharacter(name, maxHealth, maxDamage, abilityTokens) {}

void Mage::TakeDamage(int32 damage)
{
    BaseCharacter::TakeDamage(damage);

    if (_currentHealth <= 10 && _abilityToken > 0)
    {
        UseAbility();
    }
}

void Mage::UseAbility()  
{
    BuffAttack();
}

void Mage::BuffAttack()
{
    _currentDamage += 5;
    std::cout << "Mage used own ability - 'Buff Attack' , damage after effect - " << _currentDamage << '\n';
}
