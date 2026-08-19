#include "Shop.h"

Shop::Shop(ItemsList& items)
{
    _items = items;
}

Item* Shop::GetTargetItem(int cost)
{
    for (auto& item : _items)
    {
        if (item.GetCost() == cost)
        {
            return &item;
        }
    }
    return nullptr;
}

Item* Shop::GetTargetItem(FString name)
{
    for (auto& item : _items)
    {
        if (item.GetName() == name)
        {
            return &item;
        }
    }
    return nullptr;
}

ItemsList& Shop::GetItems()
{
    return  _items;
}
