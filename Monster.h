#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <cmath>
#include <iostream>

enum class MonsterType {
    Goblin,
    Skeleton,
    Orc
};

class Monster {
private:
    MonsterType type;
    std::string name;

    int health;
    int damage;
    int stage;
    int exp;

    double swordDropRate; // Sword �����
    double armorDropRate; // Armor �����

    int goldDropMin;      // ��� �ּҰ�
    int goldDropMax;      // ��� �ִ밪
    int goldDrop;         // ���� ����� ���

 

public:
    Monster(int stage);


    void generateRandomMonster();

    // �� ���� ü�� ��� 
    int calculateGoblinHealth(int stage);
    int calculateSkeletonHealth(int stage);
    int calculateOrcHealth(int stage);

    // �� ���� ������ ��� 
    int calculateGoblinDamage(int stage);
    int calculateSkeletonDamage(int stage);
    int calculateOrcDamage(int stage);

    // ����, �� ����� ���
    double calculateSwordDropRate(int stage);
    double calculateArmorDropRate(int stage);

    // ��� ��� �� ����ġ ���
    void calculateGoldDrop(int stage);
    void calculateExp(int stage);

    void printMonsterInfo() const;
};

#endif