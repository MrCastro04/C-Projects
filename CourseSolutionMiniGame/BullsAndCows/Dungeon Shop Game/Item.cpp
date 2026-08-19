#include "Item.h"

Item::Item(FString name, int cost)
{
    _name = name;
    _cost = cost;
}

FString Item::GetName() const{ return _name; }
int Item::GetCost() const{ return _cost; }
