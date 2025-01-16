#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include "Inventory.h"

using namespace std;


// 수정!!
class Player {
private:
	string name;
	int level = 1;
	int maxHealth;
	int currentHealth;
	int attack;
	int gold;
	int exp;
	int attack_1;
	int attack_2;
	int attack_3;
	shared_ptr<Consumable> inventory;
	shared_ptr<Equipment> equipment = make_shared<Equipment>();

	void calculateMaxHealth();
public:

	Player(const string& playerName);

    void showStat() const;

    // 금액 관련 함수
    int getGold() const;
    
	void setEquipStat() 
	{ 
		attack += equipment->equipStat_Sword();
		maxHealth += equipment->equipStat_Armor();
	}
	shared_ptr<Equipment> getEquip() { return equipment; }

    // 공격력 관련 함수
    int getAttack() const;
    void setAttack(int newAttack);

    // 인벤토리 관련 함수
    void addItem(const string& item);
    void delItem(const string& item);
	void setInventory(shared_ptr<Consumable> inven) { inventory = inven; }
  
    //체력 회복 관련 함수
    void recoverHealth();                                     
    int getMaxHealth() const;    //    ***** 추가 *****   Skillinterfaces 참조
    void Heal(int amount);

    //경험치 획득과 레벨업 관련 함수
    int getLevel()const;
    void levelUp();
    void gainExp(int amount);
	int getEXP() { return exp; }
	int getMaxEXP() { int maxExp = (100 * (1 + level) * level) / 2; return exp; }

    //데미지와 관련된 함수
    void takeDamage(int amount);

    //몬스터 공격시 출력
    void attackMonster();

    //getter setter 추가
    std::string getName() const;
    int getCurrHP()const;
    void setCurrHP(int newHP);

    //체력바 구현
    std::string displayHealthBar();

    //골드획득 소모
    void gainGold(int newGold);
    void useGold(int newGold);
};

#endif