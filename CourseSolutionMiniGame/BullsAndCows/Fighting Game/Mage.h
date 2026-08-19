#pragma once
#include "BaseCharacter.h"

class Mage : public BaseCharacter
{
    
public:
    Mage(FString name,int32 maxHealth, int32 maxDamage, int32 abilityTokens);
    void TakeDamage(int32 damage) override;
    
protected:                     
    void UseAbility() override;
    
private:
    void BuffAttack();
};
