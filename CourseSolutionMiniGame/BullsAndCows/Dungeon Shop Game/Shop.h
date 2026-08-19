#pragma once

#include <vector>
#include "Item.h"

using ItemsList = std::vector<Item>;
using FString = std::string;

class Shop
{
public:
    Shop(ItemsList& items);
    
    Item* GetTargetItem(int cost);
    Item* GetTargetItem(FString name);
    ItemsList& GetItems();

private:
    ItemsList _items;
};
