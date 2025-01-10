#ifndef PLAYER_H
#define PLAYER_H

#include <string>

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

public:
   
    Player(const std::string& playerName);

    // 스탯
    void showStat() const;

    // 추후 추가 
  
};

#endif