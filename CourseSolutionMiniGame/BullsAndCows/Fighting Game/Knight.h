#pragma once
#include "BaseCharacter.h"

class Knight : public BaseCharacter
{
public:
    Knight(FString name,int32 maxHealth, int32 maxDamage, int32 abilityTokens);
    void UseAbility() override;
    void TakeDamage(int32 damage) override;

private:
    void HealAbility();
};
