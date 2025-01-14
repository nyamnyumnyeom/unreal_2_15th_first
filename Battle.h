#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"
#include "Monster.h"
#include "SkillManager.h"
#include "Inventory.h"

class Battle 
{
private:
	int stage = 1;
	bool canKeepGoing = false;

	Player* nowPlayer;
	Monster* nowMonster;
	SkillManager* skill;
	Consumable* item;

public:
	//������, �Ҹ���
	Battle(Player& player, Monster& monster) : nowPlayer(&player), nowMonster(&monster) {}
	~Battle() { delete nowPlayer, nowMonster; }

	//���� stage�� ��ȯ�ϴ� getter
	int getStage() const { return stage; }
	//stage�� �ʱ�ȭ�ϴ� setter
	void setStage(const int& setS) { stage = setS; }

	//���� ���� �� ���� ���θ� ��ȯ�ϴ� getter
	bool getCanKeepGoing() const { return canKeepGoing; }

	//�÷��̾�� ������ ������ ���ÿ� ���
	void showStats();

	//-------�÷��̾� �ൿ-------
	//�÷��̾� �� : �⺻ ����
	void playerAttack();

	//�÷��̾� �� : ��ų ���
	void playerSkill();

	//�÷��̾� �� : ������ ���
	void playerItem();

	//�÷��̾� �ൿ �������� ����
	void playerBehavior();

	//-------���� �ൿ-------
	//���� �� : �⺻ ����
	void monsterAttack();

	//���� ���� ���� �Լ� - Battle Ŭ������ �Լ����� �ڵ����� ���
	void startBattle();
};

#endif