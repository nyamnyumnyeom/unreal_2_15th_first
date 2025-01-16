#include "Player.h"
#include <iostream>
#include <cmath>

// 일단 대충 설정해놔서 다시 해야 합니다 ...
Player::Player(const std::string& playerName)
    : name(playerName), level(1), maxHealth(200), currentHealth(200), attack(30), exp(0) , gold(100) {
}

void Player::calculateMaxHealth() {
    if (level == 1) {
        maxHealth = 100; // 레벨 1의 초기 HP
    }
    else {
        maxHealth = static_cast<int>(maxHealth + level + std::round(maxHealth / 7.0)); // 반올림 처리
    }
    currentHealth = maxHealth; // 현재 체력을 최대 체력으로 설정
}


// 추후 추가
void Player::showStat() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Health: " << currentHealth << "/" << maxHealth << std::endl;
        std::cout << "Attack: " << attack << std::endl;
        std::cout << "Gold: " << gold << std::endl;
        std::cout << "EXP: " << exp << std::endl;

		inventory->showInventory();
    }
int Player::getGold() const {
    return gold;
}


void Player::gainGold(int newGold) {
    gold += newGold;
    std::cout << name << "가 " << newGold << " 골드를 획득했습니다. 현재 골드: " << gold << std::endl;

}
//void Player::setGold(int newGold) {
//    gold = newGold;
//    std::cout << name << "의 골드 보유량이 변화했습니다. 현재 골드: " << gold << std::endl;
//}
void Player::useGold(int newGold) {
    gold -= newGold;
    std::cout << name << "가 " << newGold << " 골드를 소모했습니다. 현재 골드: " << gold << std::endl;
}

int Player::getAttack() const {
    return attack;
}

void Player::setAttack(int newAttack) {
    attack = newAttack;
}

void Player::addItem(const std::string& item) {
    inventory->itemGet(item);
}

void Player::delItem(const std::string& item) {
	inventory->itemUse(item);
}

void Player::recoverHealth() {
    int recoveryAmount = maxHealth / 2;
    currentHealth = std::min(currentHealth + recoveryAmount, maxHealth);
    std::cout << "현재 체력이 " << recoveryAmount << "만큼 회복되었습니다! 현재 체력 : " << currentHealth << "/" << maxHealth << std::endl;
}

int Player::getMaxHealth() const {              //*******추가******** Skillinterfaces 참조
    return maxHealth;
}

void Player::Heal(int amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
    cout << "플레이어 체력이 " << amount << "만큼 회복되었습니다. (현재 체력: " << currentHealth << "/" << maxHealth << ")\n";
}

//레벨업
void Player::levelUp() {
    std::string levelUpEffect[5] = {
        "    * LEVEL UP *    ",
        "  *-----------------*  ",
        " * Congratulations! * ",
        "  *-----------------*  ",
        "    * LEVEL UP *    "
    };
    for (const std::string& line : levelUpEffect) {
        std::cout << line << std::endl;
    }
    level++;
    maxHealth += level + (maxHealth / 7);
    currentHealth = maxHealth;
    attack += level + (attack / 10);
    exp = 0;

    std::cout << "Level up! current level is: " << level << ", MaxHealth: " << currentHealth
        << ", Attack: " << attack << endl;
}

//레벨
int Player::getLevel()const {
    return level;
}

//경험치 획득
void Player::gainExp(int amount) {
    exp += amount;

	int maxExp = (100 * (1 + level) * level) / 2;
    
    if (exp >= maxExp) {
        exp -= maxExp;
        levelUp();

    }
}

//입은 데미지를 입력받아 현재체력 수정,음수 일시 0으로 고정
void Player::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
    }
    std::cout << name << "가 " << amount << "의 피해를 입습니다, 남은체력: " << currentHealth << endl;
}

//몬스터 공격시 문구 출력
void Player::attackMonster() {
    std::cout << name << "가 " << attack << "의 데미지로 공격합니다! " << endl;
}

//player쪽 반환함수 추가
std::string Player::getName() const {
    return name;
}
int Player::getCurrHP()const {
    return currentHealth;
}
void Player::setCurrHP(int newHP) {
    currentHealth = newHP;
}
//체력바 표시


std::string Player::displayHealthBar() {
    const int totalBars = 20;
    int filledBars = round(double(currentHealth) / double(maxHealth) * 20);
    int emptyBars = totalBars - filledBars;
    std::string bar = std::string(filledBars, '=') + std::string(emptyBars, ' ');
    if (round(double(currentHealth) / double(maxHealth) * 100) == 100) {
        std::cout << "\r| HP:[" << bar << "] " << round(double(currentHealth) / double(maxHealth) * 100) << "%           |";
    }
    else {
        std::cout << "\r| HP:[" << bar << "] " << round(double(currentHealth) / double(maxHealth) * 100) << "%            |";
    }
    // 캐리지 리턴으로 한 줄에 출력
    std::cout.flush();
    return "";
}

/*void Player::gainExp(int amount) {
    exp += amount;
    int maxExp = (100 * (1 + level) * level) / 2;
    if (exp >= maxExp) {
        exp -= maxExp;
        levelUp();
    }
    std::cout << name << "가 " << amount << " 경험치를 획득했습니다. (현재 경험치: " << exp << "/" << maxExp << ")\n";
}*/
