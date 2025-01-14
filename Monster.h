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
    int currentHP;

    double swordDropRate; // Sword 드랍율
    double armorDropRate; // Armor 드랍율

    int goldDropMin;      // 골드 최소값
    int goldDropMax;      // 골드 최대값
    int goldDrop;         // 실제 드랍될 골드

 

public:
    Monster(int stage);

    std::string getName() const;

 
    int getCurrentHP() const;
 
    void setCurrentHP(int hp);

    // 몬스터 공격력 
    int getAttack() const;

    void generateRandomMonster();

    // 각 몬스터 체력 계산 
    int calculateGoblinHealth(int stage);
    int calculateSkeletonHealth(int stage);
    int calculateOrcHealth(int stage);

    // 각 몬스터 데미지 계산 
    int calculateGoblinDamage(int stage);
    int calculateSkeletonDamage(int stage);
    int calculateOrcDamage(int stage);

    // 무기, 방어구 드랍율 계산
    double calculateSwordDropRate(int stage);
    double calculateArmorDropRate(int stage);

    // 골드 계산 및 경험치 계산
    void calculateGoldDrop(int stage);
    void calculateExp(int stage);

    void printMonsterInfo() const;
};

#endif