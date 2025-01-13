#include "Shop.h"
#include "printimg.cpp"
#include <thread> 
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

using namespace std;

// 상점 열기
void Shop::openShop(Player& player) {
    while (true) {
        cout << "\n=== 상점 ===\n";
        cout << "1. 구매 HP 포션 (100 Gold)\n";
        cout << "2. 스킬 구매 (1000 Gold)\n";
        cout << "3. 상점 나가기\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            if (player.getGold() >= 100) {
                player.setGold(player.getGold() - 100);
                player.addItem("hppotion", 1); 
                cout << "HP 포션을 구매했습니다.\n";
            }
            else {
                cout << "돈이 부족합니다.\n";
            }
        }
        else if (choice == 2) {
                buySkill(player);
        }
        else if (choice == 3) {
            cout << "상점을 나갑니다.\n";
            break;
        }
        else if (choice == 99) {
            player.setGold(player.getGold() + 100000);
        }
        else {
            cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }
}


void Shop::buySkill(Player& player) {
    if (player.getGold() >= 1000) {
        player.setGold(player.getGold() - 1000);  
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

        if (randomChance <= 3) {  // 3% 확률
            // attack_1 레벨 1증가
            cout << "1!!!" << endl;
        }
        else if(randomChance >= 4 && randomChance <= 6) {
            // attack_2 레벨 1증가
            cout << "2!!!" << endl;
        }
        else if (randomChance >= 7 && randomChance <= 9) {
            // attack_3 레벨 1증가
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
