#pragma once
#include "Client.h"
#include "Shop.h"

class ShopGame
{
public:
    void Play();

private:
    ItemsList* _items = nullptr;
    Shop* _shop = nullptr;
    Client* _client = nullptr;

    void CreateItemsList(int maxCountItems);
    void CreateShop(ItemsList& itemsList);
    void CreateClient(int startMoney);

    void DeleteItemsList();
    void DeleteShop();
    void DeleteClient();

    Item* GetRandomItem();
    FString GetRandomItemName();
    int GetRandomRange(int Min, int Max);
};
