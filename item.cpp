#include "item.h"
#include <iostream>

void HPPotion::use(Player& player) {
    if (player.getCurrentHealth() <= player.getMaxHealth() * 0.5) {
        int healAmount = player.getMaxHealth() * 0.2;
        player.setCurrentHealth(player.getCurrentHealth() + healAmount);

        // 현재 체력이 최대 체력을 초과하지 않도록 조정
        if (player.getCurrentHealth() > player.getMaxHealth()) {
            player.setCurrentHealth(player.getMaxHealth());
        }

        std::cout << "HP 포션을 사용하여 체력이 " << healAmount << " 회복되었습니다.\n";
    }
    else {
        std::cout << "현재 체력이 최대 체력의 50% 이상이므로 HP 포션을 사용할 수 없습니다.\n";
    }
}

void Resurrection::use(Player& player) {
    // 부활 로직 구현 (예: 플레이어의 상태를 초기화)
    player.resurrect();
    std::cout << "부활권을 사용하여 부활했습니다!\n";
}
