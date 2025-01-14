#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <map>
using namespace std;

//----------인벤토리 인터페이스----------
class IInventory {
	virtual void showInventory() = 0;
	virtual void itemGet(const string& itemName) = 0;
};

//----------소모품 인벤토리----------
class Consumable : IInventory {
private:
	map<string, int> slot_consum;

public:
	//생성자 및 인벤토리-소모품 getter
	Consumable() = default;
	map<string, int> getConsumable() { return slot_consum; }

	//인벤토리-소모품 아이템 조회
	void showInventory();
	//아이템 획득
	void itemGet(const string& itemName);

	//아이템 사용
	int itemUse(const string& itemName);
};

//----------장비 인벤토리----------
class Equipment : IInventory {
private:
	map<string, int> slot_Equip;

public:
	//생성자 및 인벤토리-소모품 getter
	Equipment() = default;
	map<string, int> getEquipment() { return slot_Equip; }

	//인벤토리 - 장비 아이템 조회
	void showInventory();
	//아이템 획득
	void itemGet(const string& itemName);

	//장비에 의한 누적 능력치 반환
	int equipStat_Sword();
	int equipStat_Armor();
};

#endif