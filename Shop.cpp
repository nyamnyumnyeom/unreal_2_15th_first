#include "Shop.h"
#include <iostream>

using namespace std;

void Shop::openShop(Player& player) {
    while (true) {
        cout << "\n=== 상점 ===\n";
        cout << "1. 구매 \n";
        cout << "2. 상점 나가기\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            
        }
        else if (choice == 2) {
            cout << "상점을 나갑니다.\n";
            break;
        }
        else {
            cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }
}