#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

//----------�Ҹ�ǰ �κ��丮----------
//�κ��丮-�Ҹ�ǰ ������ ��ȸ
void Consumable::showInventory()
{
	if (slot_consum.empty())
	{
		cout << "Log : �κ��丮�� ǥ���� �� �ִ� �������� �����ϴ�." << endl;
		return;
	}

	cout << "�� ------------- �Ҹ�ǰ -------------��" << endl;
	for (auto iter = slot_consum.begin(); iter != slot_consum.end(); iter++)
	{
		cout << "|" << setw(15) << left << iter->first << "  : " << setw(16) << right << iter->second << "|" << endl;
	}
	cout << "�� ------------ �κ��丮 ------------��" << endl;
}

//������ ȹ��
void Consumable::itemGet(string itemName)
{
	//�κ��丮�� �ش� �������� �ִ��� �˻��Ͽ� [������ �߰� or ������ ���� ����]
	map<string, int>::iterator iter = slot_consum.find(itemName);
	if (iter == slot_consum.end())
	{
		slot_consum.insert(make_pair(itemName, 1));
		cout << "������ '" << itemName << "'��/�� �Ҹ�ǰ �κ��丮�� �����մϴ�." << endl;
	}
	else
	{
		iter->second++;
		cout << "������ '" << itemName << "'��/�� �Ҹ�ǰ �κ��丮�� �����մϴ�. ���� ���� : " << iter->second << "��" << endl;
	}
}

//������ ���
int Consumable::itemUse(string itemName)
{
	map<string, int>::iterator iter = slot_consum.find(itemName);
	if (iter == slot_consum.end())
	{
		cout << "Error : ����Ϸ��� �������� �����ϴ�.";
		return 0;
	}

	iter->second--;
	cout << "������ '" << itemName << "'��/�� 1�� ����մϴ�. ���� ���� : " << iter->second << "��" << endl;

	if (iter->second == 0)
	{
		slot_consum.erase(itemName);
	}
	return 1;
}


//----------��� �κ��丮----------
//�κ��丮 - ��� ������ ��ȸ
void Equipment::showInventory()
{
	if (slot_Equip.empty())
	{
		cout << "Log : ���� �������� �������� �����ϴ�." << endl;
		return;
	}

	cout << "�� ------------- ������ -------------��" << endl;
	for (auto iter = slot_Equip.begin(); iter != slot_Equip.end(); iter++)
	{
		cout << "|" << setw(15) << left << iter->first << "  : " << setw(16) << right << iter->second << "|" << endl;
	}
	cout << "�� ------------ ȹ����� ------------��" << endl;
}

//������ ȹ��
void Equipment::itemGet(string itemName)
{
	//�κ��丮�� �ش� �������� �ִ��� �˻��Ͽ� [������ �߰� or ������ ���� ����]
	map<string, int>::iterator iter = slot_Equip.find(itemName);
	if (iter == slot_Equip.end())
	{
		slot_Equip.insert(make_pair(itemName, 1));
		cout << "'" << itemName << "'��/�� �����մϴ�." << endl;
	}
	else
	{
		iter->second++;
		cout << "'" << itemName << "'��/�� ȹ���Ͽ� ���� ��� ��ȭ�˴ϴ�. ��ø Ƚ�� : " << iter->second << "ȸ" << endl;
	}
}

//��� ���� ���� �ɷ�ġ ��ȯ
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