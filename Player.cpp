#include "Player.h"
#include <iostream>

// 일단 대충 설정해놔서 다시 해야 합니다 ...
Player::Player(const std::string& playerName)
    : name(playerName), level(1), maxHealth(200), currentHealth(200), attack(30), exp(0) {
}

// 추후 추가
void Player::showStat() const {
   
}


