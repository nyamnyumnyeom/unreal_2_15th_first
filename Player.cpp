#include "Player.h"
#include <iostream>
#include <cmath>

// .
Player::Player(const std::string& playerName)
    : name(playerName), level(1), maxHealth(200), currentHealth(200), attack(30), exp(0) , gold(100) {
}

void Player::calculateMaxHealth() {
    if (level == 1) {
        maxHealth = 100; // ���� 1�� �ʱ� HP
    }
    else {
        maxHealth = static_cast<int>(maxHealth + level + std::round(maxHealth / 7.0)); // �ݿø� ó��
    }
    currentHealth = maxHealth; // ���� ü���� �ִ� ü������ ����
}

// ���� �߰�
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

void Player::recoverHealth() {
    int recoveryAmount = maxHealth / 2;
    currentHealth = std::min(currentHealth + recoveryAmount, maxHealth);
    std::cout << "���� ü���� " << recoveryAmount << "��ŭ ȸ���Ǿ����ϴ�! ���� ü�� : " << currentHealth << "/" << maxHealth << std::endl;
}
