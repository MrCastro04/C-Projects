#include "ShopGame.h"

#include <iostream>
#include <random>

#include "Shop.h"

void ShopGame::Play()
{
    int clientStartMoney = 300; 
    CreateItemsList(10);
    CreateShop(*_items);
    CreateClient(clientStartMoney);

    _client->TryBuy(*GetRandomItem());

    DeleteItemsList();
    DeleteShop();
    DeleteClient();
}

void ShopGame::CreateItemsList(int maxCountItems)
{
    _items = new ItemsList();

    for (int i = 1; i < maxCountItems; i++)
    {
        int cost = 100 * i;
        FString name = "Item" + std::to_string(i);

        _items->push_back(Item(name, cost));
    }
}

void ShopGame::CreateShop(ItemsList& items)
{
    _shop = new Shop(items);
}

void ShopGame::CreateClient(int moneyStartMoney)
{
    _client = new Client(moneyStartMoney);
}

void ShopGame::DeleteItemsList()
{
    _items->clear();
    delete _items;
}

void ShopGame::DeleteShop()
{
    delete _shop;
}

void ShopGame::DeleteClient()
{
    delete _client;
}

Item* ShopGame::GetRandomItem()
{
    FString name = GetRandomItemName();
    Item* item = _shop->GetTargetItem(name);

    if (item != nullptr)
        return item;
    
    std::cout << "This item is not exist";

    return nullptr;
}

FString ShopGame::GetRandomItemName()
{
    int randIndex = GetRandomRange(1, _items->size());
    FString itemName = "Item" + std::to_string(randIndex);

    return itemName;
}

int ShopGame::GetRandomRange(int Min, int Max)
{
    static std::mt19937 Generator(static_cast<unsigned int>(std::time(nullptr)));

    std::uniform_int_distribution<int> Distribution(Min, Max);

    return Distribution(Generator);
}
