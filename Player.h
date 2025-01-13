#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>

using namespace std;


// ����!!
class Player {
private:
    string name;
    int level;
    int maxHealth;
    int currentHealth;
    int attack;
    int gold;
    int exp;
    int attack_1;
    int attack_2;
    int attack_3;
    map<string, int> inventory;
    
    void calculateMaxHealth();
public:
   
    Player(const string& playerName);

    void showStat() const;

    // �ݾ� ���� �Լ�
    int getGold() const;
    void setGold(int newGold);

    // ���ݷ� ���� �Լ�
    int getAttack() const;
    void setAttack(int newAttack);

    // �κ��丮 ���� �Լ�
    void addItem(const string& item, int count);
    void delItem(const string& item, int count);
  

    //����ġ ȹ��� ������ ���� �Լ�
    void levelUp();
    void gainExp(int amount);

    //�������� ���õ� �Լ�
    void takeDamage(int amount);
    
    //���� ���ݽ� ���
    void attackMonster();
};

#endif