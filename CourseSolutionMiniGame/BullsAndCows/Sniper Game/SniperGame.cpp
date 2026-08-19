#include "SniperGame.h"

#include <iostream>
#include <random>

void SniperGame::Play()
{
    CreateField(20, 5, 2);
}

void SniperGame::CreateField(int maxFieldSize, int minDistanceBetweenTargets, int countOfTargets)
{
    if (_mapGame == nullptr)
    {
        _mapGame = new FString;
        _mapSymbols = new std::map<int, char>;
    }

    int tempCount = countOfTargets;

    for (int i = 0; i < maxFieldSize; i++)
    {
        int hasMarkAsTarget = GetRandomRange(0, 1);

        if (hasMarkAsTarget == 0 || tempCount <= 0)
        {
            SetEmpty(i);
            continue;
        }
        
        bool isAreaSafe = true;
        for (int checkIndex = i - minDistanceBetweenTargets; checkIndex < i; checkIndex++)
        {
            if (IsTargetOnIndex(checkIndex))
            {
                isAreaSafe = false;
                break;            
            }
        }
        
        if (isAreaSafe)
        {
            SetTarget(i);
            tempCount--;
        }
        else
        {
            SetEmpty(i);
        }
    }
    std::cout << *_mapGame << '\n';
}

void SniperGame::SetEmpty(int index) const
{
    _mapGame->push_back(GetEmptySymbol());
    (*_mapSymbols)[index] = GetEmptySymbol();
}

void SniperGame::SetTarget(int index) const
{
    _mapGame->push_back(GetTargetSymbol());
    (*_mapSymbols)[index] = GetTargetSymbol();
}

bool SniperGame::IsTargetOnIndex(int index) const
{
    if (_mapGame == nullptr || index < 0 || index >= _mapGame->size())
    {
        return false;
    }

    const char value = _mapSymbols->at(index);

    if (value == GetTargetSymbol())
    {
        return true;
    }

    return false;
}

int SniperGame::GetRandomRange(int min, int max) const
{
    static std::mt19937 Generator(static_cast<unsigned int>(std::time(nullptr)));

    std::uniform_int_distribution<int> Distribution(min, max);

    return Distribution(Generator);
}
