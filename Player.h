#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// ����!!
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

    // ����
    void showStat() const;

    // ���� �߰� 
  
};

#endif