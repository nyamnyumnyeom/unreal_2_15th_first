#include "Player.h"
#include <iostream>
#include <cmath>

// 일단 대충 설정해놔서 다시 해야 합니다 ...
Player::Player(const std::string& playerName)
    : name(playerName), level(1), maxHealth(200), currentHealth(200), attack(30), exp(0) , gold(100) {
}

void Player::calculateMaxHealth() {
    if (level == 1) {
        maxHealth = 100; // 레벨 1의 초기 HP
    }
    else {
        maxHealth = static_cast<int>(maxHealth + level + std::round(maxHealth / 7.0)); // 반올림 처리
    }
    currentHealth = maxHealth; // 현재 체력을 최대 체력으로 설정
}

// 추후 추가
void Player::showStat() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Health: " << currentHealth << "/" << maxHealth << std::endl;
        std::cout << "Attack: " << attack << std::endl;
        std::cout << "Gold: " << gold << std::endl;
        std::cout << "EXP: " << exp << std::endl;

        std::cout << "Inventory: \n";
        for (const auto& item : inventory) {
            std::cout << item.first << ": " << item.second << std::endl;
        }
    }
int Player::getGold() const {
    return gold;
}

void Player::setGold(int newGold) {
    gold = newGold;
}

int Player::getAttack() const {
    return attack;
}

void Player::setAttack(int newAttack) {
    attack = newAttack;
}

void Player::addItem(const std::string& item, int count) {
    inventory[item] += count;
}

void Player::delItem(const std::string& item, int count) {
    inventory[item] -= count;

}
//레벨업
void Player::levelUp() {
    level++;
    maxHealth += level + (maxHealth / 7);
    currentHealth = maxHealth;
    attack += level + (attack / 10);
    exp = 0;
    std::cout << "Level up! current level is: " << level << ", MaxHealth: " << currentHealth
        << ", Attack: " << attack << endl;
}
//경험치 획득
void Player::gainExp(int amount) {
    exp += amount;
    int maxExp = (100 * (1 + level) * level) / 2;
    if (exp >= maxExp) {
        exp -= maxExp;
        levelUp();

    }
}
//입은 데미지를 입력받아 현재체력 수정,음수 일시 0으로 고정
void Player::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
    }
    std::cout << name << "가 " << amount << "의 피해를 입습니다, 남은체력: " << currentHealth << endl;
}

//몬스터 공격시 문구 출력
void Player::attackMonster() {
    std::cout << name << "가 "<<attack<<"의 데미지로 공격합니다! " << endl;
}