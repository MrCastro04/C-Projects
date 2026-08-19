#pragma once
/* мини игра снайпер
 *
 * 1) создается X мешеней , символ - '$'
 * 2) игрок может выстрелить , перемещая каретку влево или вправо
 * 3) всего игрок имеет X выстрелов
 * 4) Цель игры збить все мешени
 */

#include <map>
# include <string>

using FString = std::string;

class SniperGame
{
public:
    void Play();
    
    constexpr char GetTargetSymbol() const;
    constexpr char GetEmptySymbol() const;

private:
    void CreateField(int maxFieldSize, int minDistanceBetweenTargets, int countOfTargets);
    void SetEmpty(int index) const;
    void SetTarget(int index) const;
    
    int GetRandomRange(int min, int max) const;
    bool IsTargetOnIndex(int index) const;
    
    FString* _mapGame = nullptr;
    std::map<int, char>* _mapSymbols = nullptr;
};

constexpr char SniperGame::GetTargetSymbol() const
{
    return '0';
}

constexpr char SniperGame::GetEmptySymbol() const
{
    return '-';
}
