#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Monster::Monster(MonsterType type, const std::string& name, int stage)
    : type(type), name(name), stage(stage) {
    std::srand(static_cast<unsigned>(std::time(0))); // 랜덤 시드 설정
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

// 드랍율 설정
double Monster::calculateSwordDropRate(int stage) {
    double dropRate = 5.0; // 초기 드랍율 5.0%

    // 디버깅 출력
    std::cout << "Stage: " << stage << ", Initial Drop Rate: " << dropRate << std::endl;

    // 스테이지별 드랍율 계산
    for (int i = 2; i <= stage; ++i) {
        double increment = dropRate * dropRate / 2.4; // 증가분 계산
        dropRate = 5.0 + increment; // 초기값에 증가분 추가

        if (dropRate > 45.0) {
            dropRate = 45.0; // 최대값 제한
            break;
        }

        // 디버깅 출력
        std::cout << "After Stage " << i << ": Drop Rate = " << dropRate << std::endl;
    }

    return dropRate;
}

double Monster::calculateArmorDropRate(int stage) {
    double dropRate = 5.0; // 초기 드랍율 5.0%

    // 스테이지별 드랍율 계산
    for (int i = 2; i <= stage; ++i) {
        dropRate = dropRate + (dropRate * dropRate / 2.4);
        if (dropRate > 45.0) {
            dropRate = 45.0; // 최대값 제한
            break;
        }
    }

    return dropRate;
}
void Monster::calculateGoldDrop(int stage) {
    // 초기값 설정
    int baseMin = 5;  // 1스테이지 초기 Gold_drop_min
    int baseMax = 10; // 1스테이지 초기 Gold_drop_max

    goldDropMin = baseMin; // 골드 최소값 초기화
    goldDropMax = baseMax; // 골드 최대값 초기화

    // 스테이지별 골드 계산
    for (int i = 2; i <= stage; ++i) {
        goldDropMin = static_cast<int>(goldDropMin * 1.1); // 최소값 정확히 10% 증가
        goldDropMax = static_cast<int>(goldDropMax * 1.1); // 최대값 정확히 10% 증가
    }

    // 디버깅용 출력
    std::cout << "Debug: Stage = " << stage
        << ", goldDropMin = " << goldDropMin
        << ", goldDropMax = " << goldDropMax << std::endl;

    // 랜덤 골드 값 생성
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
    if (stage == 1) return 4;
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
    std::cout << "골드 드랍: " << goldDrop << "G " << "min: " << goldDropMin << "max : " << goldDropMax;
    //std::cout << "exp: " << exp;


}