#include "Player.h"
#include <iostream>

// �ϴ� ���� �����س��� �ٽ� �ؾ� �մϴ� ...
Player::Player(const std::string& playerName)
    : name(playerName), level(1), maxHealth(200), currentHealth(200), attack(30), exp(0) {
}

// ���� �߰�
void Player::showStat() const {
   
}


