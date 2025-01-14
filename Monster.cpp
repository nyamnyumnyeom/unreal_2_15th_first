#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Monster::Monster(int stage)
    : type(type), name(name), stage(stage) {
  
    generateRandomMonster();
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

void Monster::printMonsterInfo() const {
    std::string typeName;
    switch (type) {
    case MonsterType::Goblin: typeName = "Goblin"; break;
    case MonsterType::Orc: typeName = "Orc"; break;
    case MonsterType::Skeleton: typeName = "Skeleton"; break;
    }

    std::cout << "=== ���� ���� ===\n";
    std::cout << "�̸�: " << name << "\n";
    std::cout << "����: " << typeName << "\n";
    std::cout << "ü��: " << health << "\n";
    std::cout << "���ݷ�: " << damage << "\n";
    std::cout << "��������: " << stage << "\n";
    std::cout << "�������: " << armorDropRate << "%\n";
    std::cout << "��������: " << swordDropRate << "%\n";
    std::cout << "��� ���: " << goldDrop << "G\n" << goldDropMin <<" ///" << goldDropMax;
}