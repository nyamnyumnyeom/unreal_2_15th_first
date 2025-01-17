﻿#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <cstdlib> // For std::rand
#include <algorithm> // For std::max

enum class MonsterType {
    Goblin,
    Skeleton,
    Orc
};

class Monster {
private:
    MonsterType type;
    std::string name;
    int stage;         // 스테이지
    int health;        // 최대 체력
    int currentHP;     // 현재 체력
    int damage;        // 공격력
    int goldDrop;      // 드랍 골드
    int goldDropMin;   // 최소 골드 드랍
    int goldDropMax;   // 최대 골드 드랍
    int exp;           // 경험치
    double swordDropRate; // 무기 드랍율
    double armorDropRate; // 방어구 드랍율

public:
    // 생성자: stage 값을 직접 전달받음
    Monster(int stage);

    // 몬스터 생성 및 속성 계산
    void generateRandomMonster();
    double calculateSwordDropRate(int stage);
    double calculateArmorDropRate(int stage);
    void calculateGoldDrop(int stage);
    void calculateExp(int stage);

    // 몬스터 체력, 공격력 계산 (타입별)
    int calculateGoblinHealth(int stage);
    int calculateGoblinDamage(int stage);
    int calculateSkeletonHealth(int stage);
    int calculateSkeletonDamage(int stage);
    int calculateOrcHealth(int stage);
    int calculateOrcDamage(int stage);

    // Getter/Setter 함수들
    std::string getName() const;
    int getCurrentHP() const;
    void setCurrentHP(int hp);
    int getAttack() const;

    void TakeDamage(int damage);

    void RewardBonus(double bonus);
};

#endif // MONSTER_H