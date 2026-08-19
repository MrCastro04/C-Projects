#pragma once
#include <string>

using FString = std::string;

class Item
{
public:
    Item(FString name , int cost);
    
    FString GetName() const;
    int GetCost() const;

private:
    FString _name;
    int _cost;
};
