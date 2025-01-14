#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Monster::Monster(int stage)
    : type(type), name(name), stage(stage) {
  
    generateRandomMonster();
    swordDropRate = calculateSwordDropRate(stage); // 무기 드랍율 계산
    armorDropRate = calculateArmorDropRate(stage); // 방어구 드랍율 계산
    calculateGoldDrop(stage);                      // 골드 계산
    calculateExp(stage);                           // 경험치 계산
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

// 무기 드랍율 계산
double Monster::calculateSwordDropRate(int stage) {
    double minDrop = 5.0; // 최소 드랍율
    double maxDrop = 45.0; // 최대 드랍율
    int maxStage = 50; // 최대 스테이지

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

// 방어구 드랍율 계산
double Monster::calculateArmorDropRate(int stage) {
    double minDrop = 5.0; // 최소 드랍율
    double maxDrop = 45.0; // 최대 드랍율
    int maxStage = 50; // 최대 스테이지

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

void Monster::calculateGoldDrop(int stage) {


    goldDropMin = 5;
    goldDropMax = 10;


    // 스테이지별 골드 계산
    for (int i = 2; i <= stage; ++i) {
        goldDropMin = static_cast<int>(std::round(goldDropMin * 1.1));
        goldDropMax = static_cast<int>(std::round(goldDropMax * 1.1));
    }

    // 최종 랜덤 값 생성
    goldDrop = goldDropMin + (std::rand() % (goldDropMax - goldDropMin + 1));

}

void Monster::calculateExp(int stage) {
    exp = 80; // 초기 경험치

    // 스테이지별 경험치 계산
    for (int i = 2; i <= stage; ++i) {
        exp += (i * 10);
    }
}

//-------------------------------------------------------------------------------------------\\

// 오크 체력
int Monster::calculateOrcHealth(int stage) {
    if (stage == 1) return 116;
    int previousHealth = calculateOrcHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 6.5));
}

// 오크 데미지 
int Monster::calculateOrcDamage(int stage) {
    if (stage == 1) return 5;
    int previousDamage = calculateOrcDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 10.5));
}

//-------------------------------------------------------------------------------------------\\

// 스켈레톤 체력
int Monster::calculateSkeletonHealth(int stage) {
    if (stage == 1) return 114;
    int previousHealth = calculateSkeletonHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.5));
}

// 스켈레톤 데미지 
int Monster::calculateSkeletonDamage(int stage) {
    if (stage == 1) return 6;
    int previousDamage = calculateSkeletonDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 7.5));
}

//-------------------------------------------------------------------------------------------\\

// 고블린 체력 
int Monster::calculateGoblinHealth(int stage) {
    if (stage == 1) return 115; // Slime 초기 체력
    int previousHealth = calculateGoblinHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.0));
}

// 고블린 데미지 
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

    std::cout << "=== 몬스터 정보 ===\n";
    std::cout << "이름: " << name << "\n";
    std::cout << "유형: " << typeName << "\n";
    std::cout << "체력: " << health << "\n";
    std::cout << "공격력: " << damage << "\n";
    std::cout << "스테이지: " << stage << "\n";
    std::cout << "방어구드랍율: " << armorDropRate << "%\n";
    std::cout << "무기드랍율: " << swordDropRate << "%\n";
    std::cout << "골드 드랍: " << goldDrop << "G\n" << goldDropMin <<" ///" << goldDropMax;
}