#pragma once

#ifndef SHOP_H
#define SHOP_H

#include "Player.h" 

class Shop {
public:
    void openShop(Player& player); // ������ ���� �޴��� ó��
    void buySkill(Player& player);
};

#endif