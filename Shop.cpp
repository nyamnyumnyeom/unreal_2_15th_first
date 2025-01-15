#include "Shop.h"
#include "printimg.cpp"
#include "Skillinterfaces.h"
#include <thread> 
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()


using namespace std;

// ���� ����
void Shop::openShop(Player& player, SkillManager& skillManager) {
    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1. ���� HP ���� (100 Gold)\n";
        cout << "2. ��ų ���� (1000 Gold)\n";
        cout << "3. ��Ȱ�� ����\n";
        cout << "4. ���� ������\n";
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
                buySkill(player,skillManager);
        }
        else if (choice == 3) {
            if (player.getGold() >= 5000) {
                player.setGold(player.getGold() - 5000);
                player.addItem("Resurrection", 1);
                cout << "��Ȱ�� �� �����߽��ϴ�.\n";
            }
            else {
                cout << "���� �����մϴ�.\n";
            }
        }
        else if (choice == 4) {
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


void Shop::buySkill(Player& player, SkillManager& skillManager) {
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

        if (randomChance <= 5) {  // 3% Ȯ�� , SkillManager�� ���� ����

            cout << "1!!!" << endl;

            if (!skillManager.HasSkill("������ ���� ��ų")) {   //��ų �������� Ȯ�� 
                skillManager.AddSkill(new Skill1());  
                cout << "[���ο� ��ų ȹ��!] ������ ���� ��ų�� ������ϴ�!\n"; 
            }
            else {
                skillManager.LevelUpSkill("������ ���� ��ų");// Skill1 ���� 1����
            }
        }
        else if(randomChance >= 6 && randomChance <= 10) {

            cout << "2!!!" << endl;

            if (!skillManager.HasSkill("ü�� ȸ�� ��ų")) {
                skillManager.AddSkill(new Skill2());
                cout << "[���ο� ��ų ȹ��!] ü�� ȸ�� ��ų�� ������ϴ�!\n";
            }
            else {
                skillManager.LevelUpSkill("ü�� ȸ�� ��ų");// Skill2 ���� 1����
            }
            
        }
        else if (randomChance >= 11 && randomChance <= 15) {

            cout << "3!!!" << endl;

            if (!skillManager.HasSkill("���� ���� ��ų")) {
                skillManager.AddSkill(new Skill3());
                cout << "[���ο� ��ų ȹ��!] ���� ���� ��ų�� ������ϴ�!\n";
            }
            else {
                skillManager.LevelUpSkill("���� ���� ��ų");// Skill3 ���� 1����
            }
            
        }
        else {
            cout << "�̷� ! ���ڰ� ���� ����ֳ׿�....\n";
        }
    }
    else {
        cout << "���� �����մϴ�.\n";
    }
}
