#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"    // Player 클래스 포함
#include "Monster.h"   // Monster 클래스 포함

class Battle {
public:
    void startBattle(Player& player, Monster& monster); // 전투 시작
};

#endif