#include "Shop.h"
#include <iostream>

using namespace std;

void Shop::openShop(Player& player) {
    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1. ���� \n";
        cout << "2. ���� ������\n";
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            
        }
        else if (choice == 2) {
            cout << "������ �����ϴ�.\n";
            break;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n";
        }
    }
}