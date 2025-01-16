#include "Shop.h"
#include "printimg.cpp"
#include "Skillinterfaces.h"
#include <thread> 
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
#include <memory>



using namespace std;

// 상점 열기
void Shop::openShop(shared_ptr<Player> player, SkillManager& skillManager, shared_ptr<Consumable> consum) {
    while (true) {
		consum->showInventory();
        cout << "\n=== 상점 ===\n";
        cout << "1. 구매 HP 포션 (100 Gold)\n";
        cout << "2. 스킬 구매 (1000 Gold)\n";
        cout << "3. 부활석 구매 (5000 Gold)\n";
        cout << "4. 상점 나가기\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) { // HP 포션 구매
            if (player->getGold() >= 100) {
                player->useGold(100);
                player->addItem("HP Potion");
                cout << "HP 포션을 구매했습니다.\n";
                Sleep(1250);
                system("cls");
            }
            else {
                cout << "돈이 부족합니다.\n";
                Sleep(1250);
                system("cls");
            }
        }
        else if (choice == 2) { // 스킬 구매
            system("cls");
            buySkill(*player, skillManager);
            Sleep(1250);
            system("cls");
        }
        else if (choice == 3) { // 부활석 구매
            if (player->getGold() >= 5000) {
                player->useGold(5000);
                player->addItem("Resurrection Stone");
                cout << "부활석을 구매했습니다.\n";
                Sleep(1250);
                system("cls");
            }
            else {
                cout << "돈이 부족합니다.\n";
                Sleep(1250);
                system("cls");
            }
        }
        else if (choice == 4) { // 상점 나가기
            cout << "상점을 나갑니다.\n";
            Sleep(1250);
            system("cls");
            break;
        }
        else if (choice == 99) { // 디버그 모드: 골드 추가
            player->gainGold(100000);
            cout << "디버그 모드: 100000 Gold가 추가되었습니다.\n";
        }
        else {
            cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }
}


void Shop::buySkill(Player& player, SkillManager& skillManager) {
    if (player.getGold() >= 1000) {
        player.useGold(1000);
        cout << "스킬상자를 구매했습니다.\n";
        Sleep(1000);
        print_close();
        std::cout << "\n";
        std::cout << "\n상자 개봉 중 .";
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5초 대기
        std::cout << "\r상자 개봉 중 ..";  // 캐리지 리턴으로 이전 줄을 덮어씀
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5초 대기
        std::cout << "\r상자 개봉 중 ...";  // 다시 덮어쓰고 출력
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5초 대기
        std::cout << "\r상자 개봉 중 .";
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5초 대기
        std::cout << "\r상자 개봉 중 ..";  // 캐리지 리턴으로 이전 줄을 덮어씀
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5초 대기
        std::cout << "\r상자 개봉 중 ...";  // 다시 덮어쓰고 출력
        std::flush(std::cout);  // 출력 버퍼를 즉시 출력
        Sleep(1000);
        std::cout << "\n";
        print_open();
        std::cout << "\n";
        Sleep(1500);
        std::cout << "\n";
        srand(time(0));  
        int randomChance = rand() % 100 + 1;  

        if (randomChance <= 3) {  // 3% 확률 , SkillManager에 따라 수정
            cout << "1!!!" << endl;
            if (!skillManager.HasSkill("데미지 증가 스킬")) {   //스킬 보유여부 확인 
                skillManager.AddSkill(new Skill1());  
                cout << "[새로운 스킬 획득!] 데미지 증가 스킬을 얻었습니다!\n"; 
            }
            else {
                skillManager.LevelUpSkill("데미지 증가 스킬");// Skill1 레벨 1증가
            }
        }
        else if(randomChance >= 4 && randomChance <= 6) {
            if (!skillManager.HasSkill("체력 회복 스킬")) {
                skillManager.AddSkill(new Skill2());
                cout << "[새로운 스킬 획득!] 체력 회복 스킬을 얻었습니다!\n";
            }
            else {
                skillManager.LevelUpSkill("체력 회복 스킬");// Skill2 레벨 1증가
            }
            cout << "2!!!" << endl;
        }
        else if (randomChance >= 7 && randomChance <= 9) {
            if (!skillManager.HasSkill("보상 증가 스킬")) {
                skillManager.AddSkill(new Skill3());
                cout << "[새로운 스킬 획득!] 보상 증가 스킬을 얻었습니다!\n";
            }
            else {
                skillManager.LevelUpSkill("보상 증가 스킬");// Skill3 레벨 1증가
            }
            cout << "3!!!" << endl;
        }
        else {
            cout << "이런 ! 상자가 텅텅 비어있네요....\n";
        }
    }
    else {
        cout << "돈이 부족합니다.\n";
    }
}
