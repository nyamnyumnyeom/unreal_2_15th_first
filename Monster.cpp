#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Monster::Monster(int stage)
    : type(type), name(name), stage(stage) {
    generateRandomMonster();
    currentHP = health; // ���� ü���� �ִ� ü������ �ʱ�ȭ
    swordDropRate = calculateSwordDropRate(stage); // ���� ����� ���
    armorDropRate = calculateArmorDropRate(stage); // �� ����� ���
    calculateGoldDrop(stage);                      // ��� ���
    calculateExp(stage);                           // ����ġ ���
}




void Monster::generateRandomMonster() {
    type = static_cast<MonsterType>(std::rand() % 3);

    switch (type) {
    case MonsterType::Goblin:
        name = "Goblin";
        health = calculateGoblinHealth(stage);
        damage = calculateGoblinDamage(stage);
        break;

    case MonsterType::Skeleton:
        name = "Skeleton";
        health = calculateSkeletonHealth(stage);
        damage = calculateSkeletonDamage(stage);
        break;

    case MonsterType::Orc:
        name = "Orc";
        health = calculateOrcHealth(stage);
        damage = calculateOrcDamage(stage);
        break;
    }
}

// ���� ����� ���
double Monster::calculateSwordDropRate(int stage) {
    double minDrop = 5.0; // �ּ� �����
    double maxDrop = 45.0; // �ִ� �����
    int maxStage = 50; // �ִ� ��������

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

// �� ����� ���
double Monster::calculateArmorDropRate(int stage) {
    double minDrop = 5.0; // �ּ� �����
    double maxDrop = 45.0; // �ִ� �����
    int maxStage = 50; // �ִ� ��������

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

void Monster::calculateGoldDrop(int stage) {


    goldDropMin = 5;
    goldDropMax = 10;


    // ���������� ��� ���
    for (int i = 2; i <= stage; ++i) {
        goldDropMin = static_cast<int>(std::round(goldDropMin * 1.1));
        goldDropMax = static_cast<int>(std::round(goldDropMax * 1.1));
    }

    // ���� ���� �� ����
    goldDrop = goldDropMin + (std::rand() % (goldDropMax - goldDropMin + 1));

}

void Monster::calculateExp(int stage) {
    exp = 80; // �ʱ� ����ġ

    // ���������� ����ġ ���
    for (int i = 2; i <= stage; ++i) {
        exp += (i * 10);
    }
}

//-------------------------------------------------------------------------------------------\\

// ��ũ ü��
int Monster::calculateOrcHealth(int stage) {
    if (stage == 1) return 116;
    int previousHealth = calculateOrcHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 6.5));
}

// ��ũ ������ 
int Monster::calculateOrcDamage(int stage) {
    if (stage == 1) return 5;
    int previousDamage = calculateOrcDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 10.5));
}

//-------------------------------------------------------------------------------------------\\

// ���̷��� ü��
int Monster::calculateSkeletonHealth(int stage) {
    if (stage == 1) return 114;
    int previousHealth = calculateSkeletonHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.5));
}

// ���̷��� ������ 
int Monster::calculateSkeletonDamage(int stage) {
    if (stage == 1) return 6;
    int previousDamage = calculateSkeletonDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 7.5));
}

//-------------------------------------------------------------------------------------------\\

// ��� ü�� 
int Monster::calculateGoblinHealth(int stage) {
    if (stage == 1) return 115; // Slime �ʱ� ü��
    int previousHealth = calculateGoblinHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.0));
}

// ��� ������ 
int Monster::calculateGoblinDamage(int stage) {
    if (stage == 1) return 5;
    int previousDamage = calculateGoblinDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 9.0));
}

std::string Monster::getName() const {
    return name;
}

// ���� ���� ü�� ��ȯ
int Monster::getCurrHP() const {
    return currentHP;
}

// ���� ���� ü�� ����
void Monster::setCurrHP(int hp) {
    if (hp < 0) {
        currentHP = 0; // ü���� 0 ���Ϸ� �������� ����
    }
    else if (hp > health) {
        currentHP = health; // �ִ� ü���� �ʰ����� ����
    }
    else {
        currentHP = hp; // ��ȿ�� ü�� ����
    }
}

// ���� ���ݷ� ��ȯ
int Monster::getAttack() const {
    return damage;
}