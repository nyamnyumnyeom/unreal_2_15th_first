#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

//----------소모품 인벤토리----------
//인벤토리-소모품 아이템 조회
void Consumable::showInventory()
{
	if (slot_consum.empty())
	{
		cout << "Log : 인벤토리에 표시할 수 있는 아이템이 없습니다." << endl;
		return;
	}

	cout << "┌------------- 소모품 -------------┐" << endl;
	for (auto iter = slot_consum.begin(); iter != slot_consum.end(); iter++)
	{
		cout << "|" << setw(26) << left << iter->first << "  : " << setw(3) << right << iter->second << " |" << endl;
	}
	cout << "└------------ 인벤토리 ------------┘" << endl;
}
//인벤토리-소모품 내역 출력
void Consumable::printConsumable(int index)
{
	auto iter = slot_consum.begin();
	for (int i = 0; i <= index; i++)
	{
		iter++;
	}
	cout << "|" << setw(15) << left << iter->first << "  : " << setw(16) << right << iter->second << "|" << endl;
}

//아이템 획득
void Consumable::itemGet(string itemName)
{
	cout << "asiodajp";
	//인벤토리에 해당 아이템이 있는지 검사하여 [아이템 추가 or 아이템 갯수 증가]
	map<string, int>::iterator iter = slot_consum.find(itemName);
	if (iter == slot_consum.end())
	{
		slot_consum.insert(make_pair(itemName, 1));
		cout << "아이템 '" << itemName << "'을/를 소모품 인벤토리에 보관합니다." << endl;
	}
	else
	{
		iter->second++;
		cout << "아이템 '" << itemName << "'을/를 소모품 인벤토리에 보관합니다. 현재 갯수 : " << iter->second << "개" << endl;
	}
}

//아이템 사용
int Consumable::itemUse(string itemName)
{
	map<string, int>::iterator iter = slot_consum.find(itemName);
	if (iter == slot_consum.end())
	{
		cout << "Error : 사용하려는 아이템이 없습니다.";
		return 0;
	}

	iter->second--;
	cout << "아이템 '" << itemName << "'을/를 1개 사용합니다. 현재 갯수 : " << iter->second << "개" << endl;

	if (iter->second == 0)
	{
		slot_consum.erase(itemName);
	}
	return 1;
}


//----------장비 인벤토리----------
//인벤토리 - 장비 아이템 조회
void Equipment::showInventory()
{
	if (slot_Equip.empty())
	{
		cout << "Log : 현재 장착중인 아이템이 없습니다." << endl;
		return;
	}

	cout << "┌ ------------- 장착중 -------------┐" << endl;
	for (auto iter = slot_Equip.begin(); iter != slot_Equip.end(); iter++)
	{
		cout << "|" << setw(15) << left << iter->first << "  : " << setw(16) << right << iter->second << "|" << endl;
	}
	cout << "└ ------------ 획득장비 ------------┘" << endl;
}
//인벤토리- 장비 내역 출력
void Equipment::printEquipment(int index)
{
	auto iter = slot_Equip.begin();
	for (int i = 0; i <= index; i++)
	{
		iter++;
	}
	cout << "|" << setw(15) << left << iter->first << "  : " << setw(16) << right << iter->second << "|" << endl;
}

//아이템 획득
void Equipment::itemGet(string itemName)
{
	//인벤토리에 해당 아이템이 있는지 검사하여 [아이템 추가 or 아이템 갯수 증가]
	map<string, int>::iterator iter = slot_Equip.find(itemName);
	if (iter == slot_Equip.end())
	{
		slot_Equip.insert(make_pair(itemName, 1));
		cout << "'" << itemName << "'을/를 장착합니다." << endl;
	}
	else
	{
		iter->second++;
		cout << "'" << itemName << "'을/를 획득하여 기존 장비가 강화됩니다. 중첩 횟수 : " << iter->second << "회" << endl;
	}
}

//장비에 의한 누적 능력치 반환
int Equipment::equipStat_Sword()
{
	map<string, int>::iterator iter = slot_Equip.find("sword");
	if (iter == slot_Equip.end())
	{
		return 0;
	}
	else
	{
		return iter->second;
	}
}
int Equipment::equipStat_Armor()
{
	map<string, int>::iterator iter = slot_Equip.find("armor");
	if (iter == slot_Equip.end())
	{
		return 0;
	}
	else
	{
		return iter->second;
	}
}