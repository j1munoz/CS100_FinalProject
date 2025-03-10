#include "gtest/gtest.h"
#include "../header/gamedata.hpp"

TEST(ShopTests, shopFill) {
    GameData data;
    Shop shop = data.getShop();

    EXPECT_EQ(shop.getItemsForSale().size(), 5);
}

TEST(ShopTests, shopPurchaseItem) {
    GameData data;
    Shop shop = data.getShop();
    Item item;

    item = shop.purchaseItem(1);

    EXPECT_EQ(shop.getItemsForSale().size(), 4);
}
