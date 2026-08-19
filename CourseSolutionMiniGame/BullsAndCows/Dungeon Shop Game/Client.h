#pragma once
#include "Shop.h"
class Client
{
public:
    Client(int money);

   void TryBuy( const Item& item);
   bool IsMoneyEnough(int itemCost) const;
   
private :
    int _money;
    ItemsList _items;
};
