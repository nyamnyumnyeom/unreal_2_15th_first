#include <iostream>
#include <vector>
#include <algorithm>

void levelUp() {
    level++;
    maxHealth += level + (maxHealth / 5);
    currentHealth = maxHealth;
    damage += level + (damage / 10);
    exp = 0;
    std::cout << "레벨업! 현재 레벨: " << level << ", 체력: " << currentHealth
        << ", 데미지: " << Attack << "\n";
}