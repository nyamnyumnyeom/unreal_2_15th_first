#include "Player.h"
#include <iostream>
#include <cmath>

// �ϴ� ���� �����س��� �ٽ� �ؾ� �մϴ� ...
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
//������
void Player::levelUp() {
    level++;
    maxHealth += level + (maxHealth / 7);
    currentHealth = maxHealth;
    attack += level + (attack / 10);
    exp = 0;
    std::cout << "Level up! current level is: " << level << ", MaxHealth: " << currentHealth
        << ", Attack: " << attack << endl;
}
//����ġ ȹ��
void Player::gainExp(int amount) {
    exp += amount;
    int maxExp = (100 * (1 + level) * level) / 2;
    if (exp >= maxExp) {
        exp -= maxExp;
        levelUp();

    }
}
//���� �������� �Է¹޾� ����ü�� ����,���� �Ͻ� 0���� ����
void Player::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
    }
    std::cout << name << "�� " << amount << "�� ���ظ� �Խ��ϴ�, ����ü��: " << currentHealth << endl;
}

//���� ���ݽ� ���� ���
void Player::attackMonster() {
    std::cout << name << "�� "<<attack<<"�� �������� �����մϴ�! " << endl;
}