#include "Shop.h"
#include "printimg.cpp"
#include <thread> 
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

using namespace std;

// ���� ����
void Shop::openShop(Player& player) {
    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1. ���� HP ���� (100 Gold)\n";
        cout << "2. ��ų ���� (1000 Gold)\n";
        cout << "3. ���� ������\n";
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            if (player.getGold() >= 100) {
                player.setGold(player.getGold() - 100);
                player.addItem("hppotion", 1); 
                cout << "HP ������ �����߽��ϴ�.\n";
            }
            else {
                cout << "���� �����մϴ�.\n";
            }
        }
        else if (choice == 2) {
                buySkill(player);
        }
        else if (choice == 3) {
            cout << "������ �����ϴ�.\n";
            break;
        }
        else if (choice == 99) {
            player.setGold(player.getGold() + 100000);
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n";
        }
    }
}


void Shop::buySkill(Player& player) {
    if (player.getGold() >= 1000) {
        player.setGold(player.getGold() - 1000);  
        cout << "��ų���ڸ� �����߽��ϴ�.\n";
        Sleep(1000);
        print_close();
        std::cout << "\n";
        std::cout << "\n���� ���� �� .";
        std::flush(std::cout);  // ��� ���۸� ��� ���
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5�� ���
        std::cout << "\r���� ���� �� ..";  // ĳ���� �������� ���� ���� ���
        std::flush(std::cout);  // ��� ���۸� ��� ���
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5�� ���
        std::cout << "\r���� ���� �� ...";  // �ٽ� ����� ���
        std::flush(std::cout);  // ��� ���۸� ��� ���
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5�� ���
        std::cout << "\r���� ���� �� .";
        std::flush(std::cout);  // ��� ���۸� ��� ���
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5�� ���
        std::cout << "\r���� ���� �� ..";  // ĳ���� �������� ���� ���� ���
        std::flush(std::cout);  // ��� ���۸� ��� ���
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.5�� ���
        std::cout << "\r���� ���� �� ...";  // �ٽ� ����� ���
        std::flush(std::cout);  // ��� ���۸� ��� ���
        Sleep(1000);
        std::cout << "\n";
        print_open();
        std::cout << "\n";
        Sleep(1500);
        std::cout << "\n";
        srand(time(0));  
        int randomChance = rand() % 100 + 1;  

        if (randomChance <= 3) {  // 3% Ȯ��
            // attack_1 ���� 1����
            cout << "1!!!" << endl;
        }
        else if(randomChance >= 4 && randomChance <= 6) {
            // attack_2 ���� 1����
            cout << "2!!!" << endl;
        }
        else if (randomChance >= 7 && randomChance <= 9) {
            // attack_3 ���� 1����
            cout << "3!!!" << endl;
        }
        else {
            cout << "�̷� ! ���ڰ� ���� ����ֳ׿�....\n";
        }
    }
    else {
        cout << "���� �����մϴ�.\n";
    }
}
