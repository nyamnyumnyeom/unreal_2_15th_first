#include "Battle.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <Windows.h>
#include "printimg.cpp"
using namespace std;

//랜덤 엔진을 사용해 확률 구현
int random(int min, int max)
{
	random_device rd;
	mt19937 rdEngine(rd());
	uniform_int_distribution<int> rdPrint(min, max);

	return rdPrint(rdEngine);
}

// 생성자
Battle::Battle(shared_ptr<Player> playerV) {
	nowPlayer = playerV;
	nowMonster = std::make_unique<Monster>(stage); // 초기 Monster 생성
}

// 스테이지를 설정
void Battle::setStage(const int& setS) {
	stage = setS;
	resetMonster(); // 스테이지 변경 시 몬스터 재생성
}

// 몬스터 재생성
void Battle::resetMonster() {
	nowMonster = std::make_unique<Monster>(stage); // 새로운 몬스터 생성
}

// 다음 스테이지로 이동
void Battle::nextStage() {
	setStage(stage + 1);
}

//플레이어와 몬스터의 스텟을 출력하는 함수
void Battle::showStats() {
	system("cls"); // 화면 지우기
	cout << setw(20) << left << "┌------------- Level " << setw(8) << right << nowPlayer->getLevel() << setw(15) << right << " -------------┐" << "          " << setw(20) << left << "┌------------- Stage " << setw(8) << right << stage << setw(15) << right << " -------------┐" << endl;
	cout << "|" << setw(21) << left << " " << setw(22) << right << "|" << "          " << "|" << setw(21) << left << " " << setw(22) << right << "|" << endl;
	//HP 출력
	cout << "|" << setw(15) << left << " HP : " << setw(7) << right << "( " << setw(7) << right << nowPlayer->getCurrHP() << " / " << setw(7) << right << nowPlayer->getMaxHealth() << " ) " << "|" << "          " <<
		"|" << setw(15) << left << " HP : " << setw(17) << right << "( " << setw(7) << right << nowMonster->getCurrentHP() << " ) " << "|" << endl;
	//AD 출력
	cout << "|" << setw(18) << left << " Attack Damage : " << setw(14) << right << "( " << setw(7) << right << nowPlayer->getAttack() << " ) " << "|" << "          " <<
		"|" << setw(18) << left << " Attack Damage : " << setw(14) << right << "( " << setw(7) << right << nowMonster->getAttack() << " ) " << "|" << endl;
	//공백
	cout << nowMonster->displayMHealthBar() << endl;
	//인벤토리-장비로 인한 스텟 증가량 출력
	cout << "|" << setw(27) << left << " AD increase from sword  : " << setw(4) << right << "( " << setw(8) << right << equip->equipStat_Sword() << setw(3) << right << " ) " << "|" << "          " << setw(16) << left << "└-------------[  " << setw(10) << right << nowMonster->getName() << setw(16) << right << "  ]-------------┘" << endl;
	cout << "|" << setw(27) << left << " HP increase from armor  : " << setw(4) << right << "( " << setw(8) << right << equip->equipStat_Armor() << setw(3) << right << " ) " << "|" << endl;
	//공백
	cout << "|" << setw(21) << left << " " << setw(22) << right << "|" << endl;
	//플레이어-골드, Exp
	cout << "|" << setw(15) << left << " Gold : " << setw(4) << right << "( " << setw(20) << right << nowPlayer->getGold() << setw(3) << right << " ) " << "|" << endl;
	cout << "|" << setw(15) << left << " EXP  : " << setw(7) << right << "( " << setw(7) << right << nowPlayer->getEXP() << " / " << setw(7) << right << nowPlayer->getMaxEXP() << " ) " << "|" << endl;

	cout << nowPlayer->displayHealthBar() << endl;
	cout << setw(16) << left << "└-------------[  " << setw(10) << nowPlayer->getName() << setw(16) << right << "  ]-------------┘" << endl;

	//체력바
	
	cout << "\n" << endl;
}

//-------플레이어 행동-------
//플레이어 턴 : 메세지 출력
void Battle::playerAttack() 
{
	cout << nowPlayer->getName() << "은/는 기본 공격을 시도했다!\n" << "입힌 피해량 : " << nowPlayer->getAttack() << endl;
	nowMonster->setCurrentHP(nowMonster->getCurrentHP() - nowPlayer->getAttack());

	attack_img();

	Sleep(750);
	system("cls");
	showStats();
}

//플레이어 턴 : 스킬 사용
void Battle::playerSkill() {
	// 스킬 목록 가져오기
	if (skill->GetSkills().empty()) {
		return;
	}

	// 무작위 스킬 선택 및 사용
	ISkill* selectedSkill = skill->GetSkills()[rand() % skill->GetSkills().size()];
	std::cout << "플레이어가 " << selectedSkill->GetName() << " 스킬을 사용합니다!\n";
	skill->UseSkill(selectedSkill->GetName(), *nowPlayer, *nowMonster);

	if (selectedSkill->GetName() == "데미지 증가 스킬")
	{
		Skill_Attack_img();
	} 
	else if (selectedSkill->GetName() == "체력 회복 스킬")
	{
		skill_Heal_img();
	}
	else if (selectedSkill->GetName() == "보상 증가 스킬")
	{
		skill_Gold_img();
	}

	Sleep(750);
	system("cls");
	showStats();
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
	if(ran < 70)
	{
		playerAttack();
	}
	else if (ran <= 100)
	{
		playerSkill();
	}
}

//-------몬스터 행동-------
//보스 공격
void Battle::bossAttack()
{
	int chance = std::rand() % 100;
	if (chance < 6)
	{
		int damage = nowPlayer->getCurrHP() / 10; // 플레이어 현재 체력의 10%
		nowPlayer->setCurrHP(nowPlayer->getCurrHP() - damage); // 플레이어 체력 감소
		std::cout << "보스의 강력한 공격으로 인해 플레이어의 현재 체력의 10%만큼의 데미지가 들어옵니다!!\n";

		Boss_Skill_img();

		Sleep(750);
		system("cls");
		showStats();
	}
	else if (chance < 12)
	{
		int healAmount = 15000; // 체력의 5% 회복
		nowMonster->setCurrentHP(nowMonster->getCurrentHP() + healAmount);
		if (nowMonster->getCurrentHP() > 300000) nowMonster->setCurrentHP(300000); // 최대 체력 초과 방지
		std::cout << "보스가 체력을 회복했습니다!\n";

		Boss_Heal();

		Sleep(750);
		system("cls");
		showStats();
	}
	else
	{
		cout << " 보스의 기본공격이 " << nowPlayer->getName() << "에게 적중했다...\n" << "받은 피해량 : 15000" << endl;
		nowPlayer->setCurrHP(nowPlayer->getCurrHP() - nowMonster->getAttack());

		monster_Attack_img();

		Sleep(750);
		system("cls");
		showStats();
	}
}

//몬스터 턴 : 기본 공격
void Battle::monsterAttack()
{
	if (nowMonster->bossManage())
	{
		bossAttack();  //보스 공격 및 스킬 호출
	}
	else
	{
		cout << nowMonster->getName() << "의 기본공격이 " << nowPlayer->getName() << "에게 적중했다...\n" << "받은 피해량 : " << nowMonster->getAttack() << endl;
		nowPlayer->setCurrHP(nowPlayer->getCurrHP() - nowMonster->getAttack());

		monster_Attack_img();

		Sleep(750);
		system("cls");
		showStats();

	}
}

//-----------전투 진행 과정 함수 - Battle 클래스의 함수들을 자동으로 재생-------------
void Battle::startBattle() {
	int stageChoose = 0;

	if (nowMonster->getName() == "Orc")
	{
		system("cls");
		ork_img();
		Sleep(2000);
	}
	else if (nowMonster->getName() == "Skeleton")
	{
		system("cls");
		skeleton_img();
		Sleep(2000);
	}
	else if (nowMonster->getName() == "Goblin")
	{
		system("cls");
		goblin_img();
		Sleep(2000);
	}
	else if (nowMonster->getName() == "Boss")
	{
		system("cls");
		Boss_img();
		Sleep(2000);
	}

	if (getStage() == 1)
	{
		stageChoose = 1;
	}
	else
	{
		while (stageChoose != 1 && stageChoose != 2) {
			showStats();
			cout << "다음 스테이지 : " << getStage() << ". 도전하시겠습니까? (도전 : 1 / 이전 스테이지 재도전 : 2)" << endl;
			cin >> stageChoose;

			if (stageChoose != 1 && stageChoose != 2) {
				cout << "잘못된 숫자를 입력하셨습니다. 다시 입력해 주세요." << endl;
			}
		}
	}

	if (stageChoose == 1) {
		cout << "[ STAGE : " << getStage() << " ]" << " 용사님의 도전에 행운이 함께하길 바랍니다..." << endl;
	}
	else if (stageChoose == 2) {
		setStage(getStage() - 1);
		cout << "[ STAGE : " << getStage() << " ]" << " 도전을 위해서 수련을 택한 용사님을 응원합니다..." << endl;
	}

	while (nowPlayer->getCurrHP() > 0 && nowMonster->getCurrentHP() > 0) {
		system("cls");
		showStats();
		Sleep(1000);
		playerBehavior();
		if (nowMonster->getCurrentHP() <= 0) {
			isPlayerLive = true;
			std::cout << "[ 승리 ] " << nowMonster->getName() << "을/를 처치했습니다. 승리를 축하합니다!\n";

			// 몬스터 보상을 플레이어에게 전달
			int goldEarned = nowMonster->getGoldDrop();
			int expEarned = nowMonster->getExp();

			nowPlayer->gainExp(expEarned);

			nowPlayer->gainGold(goldEarned);  // 골드 추가
			//nowPlayer->addExp(expEarned);    // 경험치 추가

			setStage(getStage() + 1);  // 다음 스테이지로 이동
			break;
		}

		//Sleep(500);
		monsterAttack();
		if (nowPlayer->getCurrHP() <= nowPlayer->getMaxHealth() / 2) {
			auto it = item->getConsumable().find("HP Potion");
			if (nowPlayer->getCurrHP() <= 0) {
				isPlayerLive = false;
				cout << "[ 패배 ] " << nowMonster->getName() << "의 강력한 일격에 " << nowPlayer->getName() << "(이)가 사망했습니다." << endl;
				break;
			}
			else if(it != item->getConsumable().end()) {
				item->itemUse("HP Potion");
				cout << "체력포션을 사용했습니다.\n";
				Sleep(500);
				nowPlayer->setCurrHP(nowPlayer->getCurrHP()+nowPlayer->getMaxHealth()/5);
			}
		}
		setTurn(getTurn() + 1);
	}

	if (item != nullptr)
	{
		if (!isPlayerLive) {
			auto it = item->getConsumable().find("Resurrection Stone");
			if (it != item->getConsumable().end()) {
				// 부활권 사용
				item->itemUse("Resurrection Stone");  // 내부적으로 삭제 처리
				cout << "부활권을 사용했습니다.\n";
				isPlayerLive = true;
				nowPlayer->setCurrHP(nowPlayer->getMaxHealth());
			}
			else {
				cout << "부활권이 없어 부활할 수 없습니다.\n";
			}
		}
	}
	Sleep(1000);
}