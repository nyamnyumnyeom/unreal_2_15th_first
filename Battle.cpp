#include "Battle.h"
#include <iostream>
#include <random>

using namespace std;

//�÷��̾�� ������ ������ ����ϴ� �Լ�
void Battle::showStats()
{
	nowPlayer->showStat();
	cout << "~~~�÷��̾�~~~\n\n\n\n" << endl;

	nowMonster->showStat();
	cout << "~~~����~~~" << endl;
}

//-------�÷��̾� �ൿ-------
//�÷��̾� �� : �޼��� ���
void Battle::playerAttack() 
{
	cout << nowPlayer->getName() << "��/�� �⺻ ������ �õ��ߴ�!\n" << "���� ���ط� : " << nowPlayer->getAttack() << endl;
	nowMonster->setCurrHP(nowMonster->getCurrHP() - nowPlayer->getAttack());
}

//�÷��̾� �� : ��ų ���
void Battle::playerSkill() 
{
		skill->UseSkill();
}

//�÷��̾� �� : ������ ���
void Battle::playerItem()
{
	cout << nowPlayer->getName() << "��/�� �κ��丮���� '" << item->itemUse() << "'��/�� ���� ����ߴ�!" << endl;
}

//�÷��̾� �ൿ �������� ����
void Battle::playerBehavior()
{
	int ran = random();
	if(ran < 60)
	{
		playerAttack();
	}
	else if (ran < 80)
	{
		playerSkill();
	}
	else
	{
		playerItem();
	}
}

//-------���� �ൿ-------
//���� �� : �⺻ ����
void Battle::monsterAttack()
{
	cout << nowMonster->getName() << "�� �⺻������ " << nowPlayer->getName() << "���� �����ߴ�...\n" << "���� ���ط� : " << nowMonster->getAttack() << endl;
	nowPlayer->setCurrHP(nowPlayer->getCurrHP() - nowMonster->getAttack());
}

//-----------���� ���� ���� �Լ� - Battle Ŭ������ �Լ����� �ڵ����� ���-------------
void Battle::startBattle()
{
	//���� 1�ܰ� / ���� �������� ���� �˸�, Go or Back ����
	bool isPlayerLive = true;
	int stageChoose = 0;
	while (stageChoose != 1 || stageChoose != 2)
	{
		showStats();
		cout << "���� �������� : " << getStage()+1 << ". �����Ͻðڽ��ϱ�? (���� : 1 / ���� �������� �絵�� : 2)" << endl;
		cin >> stageChoose;

		if (stageChoose != 1 || stageChoose != 2)
		{
			cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
		}
	}

	//���� 2�ܰ� / �������� ����
	if (stageChoose == 1)
	{
		setStage(getStage() + 1);
		cout << "[ STAGE : " << getStage() << " ]" << " ������ ������ ����� �Բ��ϱ� �ٶ��ϴ�..." << endl;
	}
	else if (stageChoose == 2)
	{
		cout << "[ STAGE : " << getStage() << " ]" << " ������ ���ؼ� ������ ���� ������ �����մϴ�..." << endl;
	}

	//���� 3�ܰ� / ���� ����, �¸� �Ǵ� ����� ���� ����
	if (nowPlayer->getLevel() > getStage())
	{
		cout << "[ " << nowPlayer->getName() << " ���� | " << nowMonster->getName() << " �İ� ] �÷��̾��� ������ �� �� ���� ���� �����ߴ�!" << endl;
		while (nowPlayer->currHP() > 0 || nowMonster->currHP() > 0)
		{
			playerBehavior();
			if (nowMonster->currHP() < 0) 
			{
				isPlayerLive = true;
				cout << "[ �¸� ] " << nowMonster->getName() << "��/�� óġ�߽��ϴ�. �¸��� �����մϴ�!" << endl;
				break; 
			}
			monsterAttack();
			if (nowPlayer->currHP() < 0)
			{
				isPlayerLive = false;
				cout << "[ �й� ] " << nowMonster->getName() << "�� ������ �ϰݿ� " << nowPlayer->getName() << "(��)�� ����߽��ϴ�." << endl;
				break;
			}
		}
	}
	else
	{
		cout << "[ " << nowMonster->getName() << " ���� | " << nowPlayer->getName() << " �İ� ] ���������� �� �� ���� ���� �÷��̾ ��������!" << endl;
		while (nowPlayer->currHP() != 0 || nowMonster->currHP() != 0)
		{
			monsterAttack();
			if (nowPlayer->currHP() < 0)
			{
				isPlayerLive = false;
				cout << "[ �й� ] " << nowMonster->getName() << "�� ������ �ϰݿ� " << nowPlayer->getName() << "(��)�� ���������ϴ�." << endl;
				break;
			}
			playerBehavior();
			{
				isPlayerLive = true;
				cout << "[ �¸� ] " << nowMonster->getName() << "��/�� óġ�߽��ϴ�. �¸��� �����մϴ�!" << endl;
				break;
			}
		}
	}

	//���� 4�ܰ� / �¸��� ���� ���� �� ���� ���� ���� Ȯ�� / ����� �κ��丮�� ��Ȱ�� �������� �˻� �� ���� ���� ���� Ȯ��
	if (isPlayerLive == true)
	{
		canKeepGoing = true;
		//���� ����
	}
	else if (isPlayerLive == false)
	{
		canKeepGoing = false;
		if (item->getConsumable().find("��Ȱ��") != item->getConsumable().end())
		{
			canKeepGoing = true;
			item->itemUse("��Ȱ��");
			cout << "���� ���� ����� �߿� �κ��丮���� ��Ȱ���� ����ϰ� ������ �ֽ��ϴ�. �ź�ο� ���� " << nowPlayer->getName() << "��/�� ���Դϴ�." << endl;
		}
	}
}



//���� ������ ����� Ȯ�� ����
int random()
{
	random_device rd;
	mt19937 rdEngine(rd());
	uniform_int_distribution<int> rdPrint(1, 100);

	return rdPrint(rdEngine);
}