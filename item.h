#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Player.h"

class Item {
public:
    virtual void use(Player& player) = 0; // 아이템 사용 메서드
    virtual const char* getDescription() const = 0; // 아이템 설명 반환 메서드
};

class HPPotion : public Item {
public:
    void use(Player& player) override;
    const char* getDescription() const override {
        return "HP 포션: 현재 체력이 최대 체력의 50% 이하일 때 체력 20% 회복.";
    }
};

class Resurrection : public Item {
public:
    void use(Player& player) override;
    const char* getDescription() const override {
        return "부활권: 플레이어가 사망했을 때 부활시킵니다.";
    }
};

#endif // ITEM_H
