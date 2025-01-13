#pragma once

#ifndef SHOP_H
#define SHOP_H

#include "Player.h" 

class Shop {
public:
    void openShop(Player& player); // 상점을 열고 메뉴를 처리
    void buySkill(Player& player);
};

#endif