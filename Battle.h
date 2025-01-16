#ifndef BATTLE_H
#define BATTLE_H

#include "SkillManager.h"
#include "Inventory.h"
#include <memory>

class Battle 
{
private:
	int stage = 1;
	int turn = 1;
	bool canKeepGoing = false;

	shared_ptr<Player> nowPlayer;    // 스마트 포인터로 변경
	unique_ptr<Monster> nowMonster;
	unique_ptr<SkillManager> skill = make_unique<SkillManager>();
	shared_ptr<Consumable> item;
	unique_ptr<Equipment> equip = make_unique<Equipment>();
	
public:
	//생성자, 소멸자
	Battle(shared_ptr<Player> playerV);
	~Battle() = default;

	void setItem(shared_ptr<Consumable> inven) { item = inven; }

	//stage를 반환하는 getter
	int getStage() const { return stage; }
	//stage를 초기화하는 setter
	void setStage(const int& setS);
	//turn을 반환하는 getter
	int getTurn() const { return turn; }
	//turn을 초기화하는 setter
	void setTurn(const int& setT) { turn = setT; }

	//전투 종료 후 승패 여부를 반환하는 getter
	bool getCanKeepGoing() const { return canKeepGoing; }

	void resetMonster();
	void nextStage();

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

	//보스 공격
	void bossAttack();

	shared_ptr<Player> getNowPlayer() { return nowPlayer; }
	shared_ptr<Consumable> getConsumable() { return item; }
};

#endif