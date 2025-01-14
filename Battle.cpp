#include "Battle.h"
#include <iostream>
#include <random>

using namespace std;

//랜덤 엔진을 사용해 확률 구현
int random(int min, int max)
{
	random_device rd;
	mt19937 rdEngine(rd());
	uniform_int_distribution<int> rdPrint(min, max);

	return rdPrint(rdEngine);
}

//플레이어와 몬스터의 스텟을 출력하는 함수
void Battle::showStats()
{
	nowPlayer->showStat();
	cout << "~~~플레이어~~~\n\n\n\n" << endl;

	nowMonster->printMonsterInfo();
	cout << "~~~몬스터~~~" << endl;
}

//-------플레이어 행동-------
//플레이어 턴 : 메세지 출력
void Battle::playerAttack() 
{
	cout << nowPlayer->getName() << "은/는 기본 공격을 시도했다!\n" << "입힌 피해량 : " << nowPlayer->getAttack() << endl;
	nowMonster->setCurrentHP(nowMonster->getCurrentHP() - nowPlayer->getAttack());
}

//플레이어 턴 : 스킬 사용
void Battle::playerSkill() 
{
	int skillSize = skill->getSkills().size();
	int num = random(0, skillSize - 1);

	skill->getSkills()[num];
	skill->UseSkill();
}

//플레이어 턴 : 아이템 사용
void Battle::playerItem()
{
	cout << nowPlayer->getName() << "은/는 인벤토리에서 '" << item->itemUse("") << "'을/를 꺼내 사용했다!" << endl;
}

//플레이어 행동 랜덤으로 선택
void Battle::playerBehavior()
{
	int ran = random(1, 100);
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

//-------몬스터 행동-------
//몬스터 턴 : 기본 공격
void Battle::monsterAttack()
{
	cout << nowMonster->getName() << "의 기본공격이 " << nowPlayer->getName() << "에게 적중했다...\n" << "받은 피해량 : " << nowMonster->getAttack() << endl;
	nowPlayer->setCurrHP(nowPlayer->getCurrHP() - nowMonster->getAttack());
}

//-----------전투 진행 과정 함수 - Battle 클래스의 함수들을 자동으로 재생-------------
void Battle::startBattle()
{
	//전투 1단계 / 다음 스테이지 정보 알림, Go or Back 선택
	bool isPlayerLive = true;
	int stageChoose = 0;
	while (stageChoose != 1 || stageChoose != 2)
	{
		showStats();
		cout << "다음 스테이지 : " << getStage()+1 << ". 도전하시겠습니까? (도전 : 1 / 이전 스테이지 재도전 : 2)" << endl;
		cin >> stageChoose;

		if (stageChoose != 1 || stageChoose != 2)
		{
			cout << "잘못된 숫자를 입력하셨습니다. 다시 입력해 주세요." << endl;
		}
	}

	//전투 2단계 / 스테이지 설정
	if (stageChoose == 1)
	{
		setStage(getStage() + 1);
		cout << "[ STAGE : " << getStage() << " ]" << " 용사님의 도전에 행운이 함께하길 바랍니다..." << endl;
	}
	else if (stageChoose == 2)
	{
		cout << "[ STAGE : " << getStage() << " ]" << " 도전을 위해서 수련을 택한 용사님을 응원합니다..." << endl;
	}

	//전투 3단계 / 전투 개시, 승리 또는 사망시 전투 종료
	if (nowPlayer->getLevel() > getStage())
	{
		cout << "[ " << nowPlayer->getName() << " 선공 | " << nowMonster->getName() << " 후공 ] 플레이어의 레벨이 알 수 없는 힘에 저항했다!" << endl;
		while (nowPlayer->getCurrHP() > 0 || nowMonster->getCurrentHP() > 0)
		{
			playerBehavior();
			if (nowMonster->getCurrentHP() < 0) 
			{
				isPlayerLive = true;
				cout << "[ 승리 ] " << nowMonster->getName() << "을/를 처치했습니다. 승리를 축하합니다!" << endl;
				break; 
			}
			monsterAttack();
			if (nowPlayer->getCurrHP() < 0)
			{
				isPlayerLive = false;
				cout << "[ 패배 ] " << nowMonster->getName() << "의 강력한 일격에 " << nowPlayer->getName() << "(이)가 사망했습니다." << endl;
				break;
			}
		}
	}
	else
	{
		cout << "[ " << nowMonster->getName() << " 선공 | " << nowPlayer->getName() << " 후공 ] 스테이지의 알 수 없는 힘이 플레이어를 짓누른다!" << endl;
		while (nowPlayer->getCurrHP() != 0 || nowMonster->getCurrentHP() != 0)
		{
			monsterAttack();
			if (nowPlayer->getCurrHP() < 0)
			{
				isPlayerLive = false;
				cout << "[ 패배 ] " << nowMonster->getName() << "의 강력한 일격에 " << nowPlayer->getName() << "(이)가 쓰러졌습니다." << endl;
				break;
			}
			playerBehavior();
			{
				isPlayerLive = true;
				cout << "[ 승리 ] " << nowMonster->getName() << "을/를 처치했습니다. 승리를 축하합니다!" << endl;
				break;
			}
		}
	}

	//전투 4단계 / 승리시 보상 정산 및 진행 가능 여부 확인 / 사망시 인벤토리에 부활권 소유여부 검사 및 진행 가능 여부 확인
	if (isPlayerLive == true)
	{
		canKeepGoing = true;
		//보상 정산
	}
	else if (isPlayerLive == false)
	{
		canKeepGoing = false;
		if (item->getConsumable().find("부활권") != item->getConsumable().end())
		{
			canKeepGoing = true;
			item->itemUse("부활권");
			cout << "눈이 점점 감기는 중에 인벤토리에서 부활권이 희미하게 빛나고 있습니다. 신비로운 힘이 " << nowPlayer->getName() << "을/를 감쌉니다." << endl;
		}
	}
}