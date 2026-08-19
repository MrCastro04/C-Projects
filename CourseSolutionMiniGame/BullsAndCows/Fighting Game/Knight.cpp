#include "Knight.h"

#include <iostream>


Knight::Knight(FString name, int32 maxHealth, int32 maxDamage, int32 abilityTokens)
: BaseCharacter(name, maxHealth, maxDamage , abilityTokens)
{
    
}

void Knight::UseAbility()
{
    HealAbility();
}

void Knight::TakeDamage(int32 damage)
{
    BaseCharacter::TakeDamage(damage);
    
    if (_currentHealth > 0 && _currentHealth <= _maxHealth / 2 && _abilityToken > 0)
    {
        _abilityToken--;    
        UseAbility();
    }
}

void Knight::HealAbility()
{
    _currentHealth += 3;
    std::cout << "Knight gained 3 hp" << '\n';
}
