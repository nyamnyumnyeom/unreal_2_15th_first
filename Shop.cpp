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

// ���� ����
void Shop::openShop(shared_ptr<Player> player, SkillManager& skillManager, shared_ptr<Consumable> consum) {
    while (true) {
		consum->showInventory();
        cout << "\n=== ���� ===\n";
        cout << "1. ���� HP ���� (100 Gold)\n";
        cout << "2. ��ų ���� (1000 Gold)\n";
        cout << "3. ��Ȱ�� ���� (5000 Gold)\n";
        cout << "4. ���� ������\n";
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) { // HP ���� ����
            if (player->getGold() >= 100) {
                player->useGold(100);
                player->addItem("HP Potion");
                cout << "HP ������ �����߽��ϴ�.\n";
                Sleep(1250);
                system("cls");
            }
            else {
                cout << "���� �����մϴ�.\n";
                Sleep(1250);
                system("cls");
            }
        }
        else if (choice == 2) { // ��ų ����
            system("cls");
            buySkill(*player, skillManager);
            Sleep(1250);
            system("cls");
        }
        else if (choice == 3) { // ��Ȱ�� ����
            if (player->getGold() >= 5000) {
                player->useGold(5000);
                player->addItem("Resurrection Stone");
                cout << "��Ȱ���� �����߽��ϴ�.\n";
                Sleep(1250);
                system("cls");
            }
            else {
                cout << "���� �����մϴ�.\n";
                Sleep(1250);
                system("cls");
            }
        }
        else if (choice == 4) { // ���� ������
            cout << "������ �����ϴ�.\n";
            Sleep(1250);
            system("cls");
            break;
        }
        else if (choice == 99) { // ����� ���: ��� �߰�
            player->gainGold(100000);
            cout << "����� ���: 100000 Gold�� �߰��Ǿ����ϴ�.\n";
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n";
        }
    }
}


void Shop::buySkill(Player& player, SkillManager& skillManager) {
    if (player.getGold() >= 1000) {
        player.useGold(1000);
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

        if (randomChance <= 3) {  // 3% Ȯ�� , SkillManager�� ���� ����
            cout << "1!!!" << endl;
            if (!skillManager.HasSkill("������ ���� ��ų")) {   //��ų �������� Ȯ�� 
                skillManager.AddSkill(new Skill1());  
                cout << "[���ο� ��ų ȹ��!] ������ ���� ��ų�� ������ϴ�!\n"; 
            }
            else {
                skillManager.LevelUpSkill("������ ���� ��ų");// Skill1 ���� 1����
            }
        }
        else if(randomChance >= 4 && randomChance <= 6) {
            if (!skillManager.HasSkill("ü�� ȸ�� ��ų")) {
                skillManager.AddSkill(new Skill2());
                cout << "[���ο� ��ų ȹ��!] ü�� ȸ�� ��ų�� ������ϴ�!\n";
            }
            else {
                skillManager.LevelUpSkill("ü�� ȸ�� ��ų");// Skill2 ���� 1����
            }
            cout << "2!!!" << endl;
        }
        else if (randomChance >= 7 && randomChance <= 9) {
            if (!skillManager.HasSkill("���� ���� ��ų")) {
                skillManager.AddSkill(new Skill3());
                cout << "[���ο� ��ų ȹ��!] ���� ���� ��ų�� ������ϴ�!\n";
            }
            else {
                skillManager.LevelUpSkill("���� ���� ��ų");// Skill3 ���� 1����
            }
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
