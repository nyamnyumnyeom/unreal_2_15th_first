#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"    // Player Ŭ���� ����
#include "Monster.h"   // Monster Ŭ���� ����

class Battle {
public:
    void startBattle(Player& player, Monster& monster); // ���� ����
};

#endif