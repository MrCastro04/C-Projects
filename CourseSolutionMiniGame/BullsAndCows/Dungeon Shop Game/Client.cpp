#include "Client.h"

#include <iostream>

Client::Client(int money)
{
    _money = money;
}

void Client::TryBuy(const Item& item)
{
    int itemCost = item.GetCost();

    if (IsMoneyEnough(itemCost))
    {
        std::cout << "Money before - "<< _money <<'\n';
        
        _money -= itemCost;
        
        std::cout << "Client succefully bought - " << item.GetName() << '\n';
        std::cout << "Item cost - " << item.GetCost() << '\n';
        std::cout << "Current money = " << _money << '\n';
    }
    else
    {
        std::cout << "Not enough money to buy item " << '\n';
        std::cout << "Client money - " << _money << '\n';
        std::cout << "Item cost - " << item.GetCost() << '\n';
    }
}

bool Client::IsMoneyEnough(int itemCost) const
{
    return _money >= itemCost;
}
