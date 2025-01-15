#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

// Monster 생성자: stage 값을 직접 전달
Monster::Monster(int stage) : stage(stage), isBoss(false) {
    // 몬스터 속성 초기화
    if (stage == 50)
    {
        isBoss = true;
        type = MonsterType::Boss;
        name = "Boss";
        health = 300000;
        damage = 15000;
        currentHP = health;
    }
    else
    {
        generateRandomMonster();
        currentHP = health; // 현재 체력을 최대 체력으로 초기화
        swordDropRate = calculateSwordDropRate(stage);
        armorDropRate = calculateArmorDropRate(stage);
        calculateGoldDrop(stage);
        calculateExp(stage);
    }
    
}

// 랜덤 몬스터 생성
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
    int maxStage = 50;     // 최대 스테이지

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

// 방어구 드랍율 계산
double Monster::calculateArmorDropRate(int stage) {
    double minDrop = 5.0; // 최소 드랍율
    double maxDrop = 45.0; // 최대 드랍율
    int maxStage = 50;     // 최대 스테이지

    double expMax = std::exp(0.1 * (maxStage - 1)) - 1;
    double expStage = std::exp(0.1 * (stage - 1)) - 1;

    return minDrop + (maxDrop - minDrop) * (expStage / expMax);
}

// 골드 드랍 계산
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

// 경험치 계산
void Monster::calculateExp(int stage) {
    exp = 80; // 초기 경험치

    // 스테이지별 경험치 계산
    for (int i = 2; i <= stage; ++i) {
        exp += (i * 10);
    }
}

// 오크 체력 계산
int Monster::calculateOrcHealth(int stage) {
    if (stage == 1) return 116;
    int previousHealth = calculateOrcHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 6.5));
}

// 오크 데미지 계산
int Monster::calculateOrcDamage(int stage) {
    if (stage == 1) return 5;
    int previousDamage = calculateOrcDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 10.5));
}

// 스켈레톤 체력 계산
int Monster::calculateSkeletonHealth(int stage) {
    if (stage == 1) return 114;
    int previousHealth = calculateSkeletonHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.5));
}

// 스켈레톤 데미지 계산
int Monster::calculateSkeletonDamage(int stage) {
    if (stage == 1) return 6;
    int previousDamage = calculateSkeletonDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 7.5));
}

// 고블린 체력 계산
int Monster::calculateGoblinHealth(int stage) {
    if (stage == 1) return 115;
    int previousHealth = calculateGoblinHealth(stage - 1);
    return static_cast<int>(previousHealth + stage + std::round(previousHealth / 7.0));
}

// 고블린 데미지 계산
int Monster::calculateGoblinDamage(int stage) {
    if (stage == 1) return 5;
    int previousDamage = calculateGoblinDamage(stage - 1);
    return static_cast<int>(previousDamage + stage + std::round(previousDamage / 9.0));
}

// Getter/Setter 함수들
std::string Monster::getName() const {
    return name;
}

int Monster::getCurrentHP() const {
    return currentHP;
}

void Monster::setCurrentHP(int hp) {
    if (hp < 0) {
        currentHP = 0;
    }
    else if (hp > health) {
        currentHP = health;
    }
    else {
        currentHP = hp;
    }
}

int Monster::getAttack() const {
    return damage;
}

void Monster::TakeDamage(int damage) {
    currentHP -= damage;
    if (currentHP < 0) currentHP = 0;
    std::cout << name << "이(가) " << damage << "의 데미지를 입었습니다. 남은 체력: " << currentHP << "\n";
}

void Monster::RewardBonus(double bonus) {
    // 보상 증가율을 골드와 경험치에 적용
    int additionalGold = static_cast<int>(goldDrop * bonus); // 보상 증가율에 의한 추가 골드
    goldDrop += additionalGold;

    int additionalExp = static_cast<int>(exp * bonus); // 보상 증가율에 의한 추가 경험치
    exp += additionalExp;

    // 보상 증가 출력
    std::cout << name << "의 보상 증가! 골드: " << additionalGold << ", 경험치: " << additionalExp << std::endl;
}

bool Monster::bossManage() const {
    return isBoss;
}

int Monster::getGoldDrop() const {
    return goldDrop;
}

int Monster::getExp() const {
    return exp;
}