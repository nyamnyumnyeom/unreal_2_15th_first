#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>

// 수정!!
class Player {
private:
    std::string name;
    int level;
    int maxHealth;
    int currentHealth;
    int attack;
    int gold;
    int exp;
    int attack_1;
    int attack_2;
    int attack_3;
    std::map<std::string, int> inventory;
public:
   
    Player(const std::string& playerName);

    void showStat() const;

    // 금액 관련 함수
    int getGold() const;
    void setGold(int newGold);

    // 공격력 관련 함수
    int getAttack() const;
    void setAttack(int newAttack);

    // 인벤토리 관련 함수
    void addItem(const std::string& item, int count);
    void delItem(const std::string& item, int count);
  
};

#endif