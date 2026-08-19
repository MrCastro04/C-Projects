#include "BaseCharacter.h"

#include <iostream>

BaseCharacter::BaseCharacter(FString name, int32 maxHealth, int32 maxDamage, int32 abilityTokens)
{
    _abilityToken = abilityTokens;
    _name = name;

    _maxHealth = maxHealth;
    _maxDamage = maxDamage;

    _currentHealth = _maxHealth;
    _currentDamage = _maxDamage;
}

void BaseCharacter::Attack(BaseCharacter& anotherCharacter) const
{
    anotherCharacter.TakeDamage(_currentDamage);
}

void BaseCharacter::TakeDamage(int32 damage)
{
    _currentHealth -= damage;
    std::cout << typeid(*this).name() << " got damage" << '\n';
    
    if (IsDead())
    {
       // TODO: лог про смерть
        std::cout << "is Dead " << _currentHealth << '\n';
    }
}

bool BaseCharacter::IsDead() const { return _currentHealth <= 0; }
