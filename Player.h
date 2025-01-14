#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

using namespace std;

class Player {
private:
    string name;
    int level;
    int maxHealth;
    int currentHealth;
    int attack;
    int gold;
    int exp;
    map<string, int> inventory;

    void calculateMaxHealth(); // 최대 체력 계산 함수

public:
    Player(const string& playerName);

    void showStat() const; // 플레이어 상태 출력 함수

    // 금액 관련 함수
    int getGold() const;
    void setGold(int newGold);

    // 공격력 관련 함수
    int getAttack() const;
    void setAttack(int newAttack);

    // 인벤토리 관련 함수
    void addItem(const string& item, int count);
    void delItem(const string& item, int count);

    // 체력 회복 관련 함수
    void recoverHealth();
    int getMaxHealth() const; // 최대 체력 반환
    void Heal(int amount);

    // 경험치 획득과 레벨업 관련 함수
    int getLevel() const;
    void levelUp();
    void gainExp(int amount);

    // 데미지와 관련된 함수
    void takeDamage(int amount);

    // 몬스터 공격 시 출력
    void attackMonster();

    // 플레이어 정보 반환 함수
    std::string getName() const;
    int getCurrHP() const;
    void setCurrHP(int newHP);

    // 부활 관련 함수
    void resurrect(); // 부활 메서드
};

#endif // PLAYER_H
