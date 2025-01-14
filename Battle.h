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
	//생성자, 소멸자
	Battle(Player& player, Monster& monster) : nowPlayer(&player), nowMonster(&monster) {}
	~Battle() { delete nowPlayer, nowMonster; }

	//현재 stage를 반환하는 getter
	int getStage() const { return stage; }
	//stage를 초기화하는 setter
	void setStage(const int& setS) { stage = setS; }

	//전투 종료 후 승패 여부를 반환하는 getter
	bool getCanKeepGoing() const { return canKeepGoing; }

	//플레이어와 몬스터의 스텟을 동시에 출력
	void showStats();

	//-------플레이어 행동-------
	//플레이어 턴 : 기본 공격
	void playerAttack();

	//플레이어 턴 : 스킬 사용
	void playerSkill();

	//플레이어 턴 : 아이템 사용
	void playerItem();

	//플레이어 행동 랜덤으로 선택
	void playerBehavior();

	//-------몬스터 행동-------
	//몬스터 턴 : 기본 공격
	void monsterAttack();

	//전투 진행 과정 함수 - Battle 클래스의 함수들을 자동으로 재생
	void startBattle();
};

#endif