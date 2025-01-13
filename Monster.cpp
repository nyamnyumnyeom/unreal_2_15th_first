#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Monster::Monster(MonsterType type, const std::string& name, int stage)
    : type(type), name(name), stage(stage) {
    std::srand(static_cast<unsigned>(std::time(0))); // ���� �õ� ����
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

// ����� ����
double Monster::calculateSwordDropRate(int stage) {
    double dropRate = 5.0; // �ʱ� ����� 5.0%

    // ����� ���
    std::cout << "Stage: " << stage << ", Initial Drop Rate: " << dropRate << std::endl;

    // ���������� ����� ���
    for (int i = 2; i <= stage; ++i) {
        double increment = dropRate * dropRate / 2.4; // ������ ���
        dropRate = 5.0 + increment; // �ʱⰪ�� ������ �߰�

        if (dropRate > 45.0) {
            dropRate = 45.0; // �ִ밪 ����
            break;
        }

        // ����� ���
        std::cout << "After Stage " << i << ": Drop Rate = " << dropRate << std::endl;
    }

    return dropRate;
}

double Monster::calculateArmorDropRate(int stage) {
    double dropRate = 5.0; // �ʱ� ����� 5.0%

    // ���������� ����� ���
    for (int i = 2; i <= stage; ++i) {
        dropRate = dropRate + (dropRate * dropRate / 2.4);
        if (dropRate > 45.0) {
            dropRate = 45.0; // �ִ밪 ����
            break;
        }
    }

    return dropRate;
}
void Monster::calculateGoldDrop(int stage) {
    // �ʱⰪ ����
    int baseMin = 5;  // 1�������� �ʱ� Gold_drop_min
    int baseMax = 10; // 1�������� �ʱ� Gold_drop_max

    goldDropMin = baseMin; // ��� �ּҰ� �ʱ�ȭ
    goldDropMax = baseMax; // ��� �ִ밪 �ʱ�ȭ

    // ���������� ��� ���
    for (int i = 2; i <= stage; ++i) {
        goldDropMin = static_cast<int>(goldDropMin * 1.1); // �ּҰ� ��Ȯ�� 10% ����
        goldDropMax = static_cast<int>(goldDropMax * 1.1); // �ִ밪 ��Ȯ�� 10% ����
    }

    // ������ ���
    std::cout << "Debug: Stage = " << stage
        << ", goldDropMin = " << goldDropMin
        << ", goldDropMax = " << goldDropMax << std::endl;

    // ���� ��� �� ����
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
    if (stage == 1) return 4;
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
    std::cout << "��� ���: " << goldDrop << "G " << "min: " << goldDropMin << "max : " << goldDropMax;
    //std::cout << "exp: " << exp;


}