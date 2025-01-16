#pragma once

#ifndef SHOP_H
#define SHOP_H

#include <memory>
#include "Player.h" 
#include "SkillManager.h"


class Shop {
public:
    void openShop(shared_ptr<Player> player, SkillManager& skillManager, shared_ptr<Consumable> consum); // 상점을 열고 메뉴를 처리  SkillManager에 따라 수정
    void buySkill(Player& player,SkillManager& skillManager);                             
};

#endif