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

    double swordDropRate; // Sword 드랍율
    double armorDropRate; // Armor 드랍율

    int goldDropMin;      // 골드 최소값
    int goldDropMax;      // 골드 최대값
    int goldDrop;         // 실제 드랍될 골드


public:
    Monster(MonsterType type, const std::string& name, int stage);

    void printMonsterInfo() const; // 몬스터 정보 출력
    void generateRandomMonster();

    // 각 몬스터 타입별 계산 함수
    int calculateGoblinHealth(int stage);
    int calculateSkeletonHealth(int stage);
    int calculateOrcHealth(int stage);

    int calculateGoblinDamage(int stage);
    int calculateSkeletonDamage(int stage);
    int calculateOrcDamage(int stage);

    double calculateSwordDropRate(int stage);
    double calculateArmorDropRate(int stage);

    void calculateGoldDrop(int stage); // 골드 계산
    void calculateExp(int stage);      // 경험치 계산

};

#endif