#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>

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
    int attack_1;
    int attack_2;
    int attack_3;
    std::map<std::string, int> inventory;
public:
   
    Player(const std::string& playerName);

    void showStat() const;

    // �ݾ� ���� �Լ�
    int getGold() const;
    void setGold(int newGold);

    // ���ݷ� ���� �Լ�
    int getAttack() const;
    void setAttack(int newAttack);

    // �κ��丮 ���� �Լ�
    void addItem(const std::string& item, int count);
    void delItem(const std::string& item, int count);
  
};

#endif