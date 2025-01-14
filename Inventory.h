#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <map>
using namespace std;

//----------�κ��丮 �������̽�----------
class IInventory {
	virtual void showInventory() = 0;
	virtual void itemGet(const string& itemName) = 0;
};

//----------�Ҹ�ǰ �κ��丮----------
class Consumable : IInventory {
private:
	map<string, int> slot_consum;

public:
	//������ �� �κ��丮-�Ҹ�ǰ getter
	Consumable() = default;
	map<string, int> getConsumable() { return slot_consum; }

	//�κ��丮-�Ҹ�ǰ ������ ��ȸ
	void showInventory();
	//������ ȹ��
	void itemGet(const string& itemName);

	//������ ���
	int itemUse(const string& itemName);
};

//----------��� �κ��丮----------
class Equipment : IInventory {
private:
	map<string, int> slot_Equip;

public:
	//������ �� �κ��丮-�Ҹ�ǰ getter
	Equipment() = default;
	map<string, int> getEquipment() { return slot_Equip; }

	//�κ��丮 - ��� ������ ��ȸ
	void showInventory();
	//������ ȹ��
	void itemGet(const string& itemName);

	//��� ���� ���� �ɷ�ġ ��ȯ
	int equipStat_Sword();
	int equipStat_Armor();
};

#endif