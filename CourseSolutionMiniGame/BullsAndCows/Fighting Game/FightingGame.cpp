#include <iostream>

#include "FightingGame.h"
#include "Knight.h"
#include "Mage.h"

void FightingGame::Play()
{
    Knight knight("Bob the knight", 20, 3, 2);
    std::cout << "Knight was spawned" << '\n';
    
    Mage mage("Pharsa the mage", 20, 3, 2);
    std::cout << "Mage was spawned" << '\n';
    
    do
    {
        knight.Attack(mage);
        mage.Attack(knight);
    }
    while (knight.IsDead() == false && mage.IsDead() == false);
}