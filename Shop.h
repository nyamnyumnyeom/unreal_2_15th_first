#pragma once

#ifndef SHOP_H
#define SHOP_H

#include "Player.h" 
#include "SkillManager.h"

class Shop {
public:
    void openShop(shared_ptr<Player> player, SkillManager& skillManager); // ������ ���� �޴��� ó��  SkillManager�� ���� ����
    void buySkill(Player& player,SkillManager& skillManager);                             
};

#endif