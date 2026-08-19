#pragma once
#include <string>

using int32 = int;
using FString = std::string;

class BaseCharacter
{
public:
    BaseCharacter(FString name, int32 maxHealth, int32 maxDamage, int32 abilityTokens);

    void Attack(BaseCharacter& anotherCharacter) const;
    bool IsDead() const;

    virtual void TakeDamage(int32 damage);

protected:
    int32 _abilityToken;
    FString _name;

    int32 _currentHealth;
    int32 _maxHealth;
    
    int32 _currentDamage;
    int32 _maxDamage;

    virtual void UseAbility() = 0;
};
