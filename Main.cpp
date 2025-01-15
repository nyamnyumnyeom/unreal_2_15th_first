#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Player.h"   // 플레이어 클래스
#include "Monster.h"  // 몬스터 클래스
#include "Battle.h"   // 전투 클래스
#include "Shop.h"     // 상점 클래스
#include "printimg.cpp"      // 이미지 출력
#include "SkillManager.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

class GameBGM {
private:
    wstring currentBgm;

    wstring stringToWstring(const string& str) {
        return wstring(str.begin(), str.end());
    }

public:
    void playBgm(const string& fileName) {
        stopBgm();
        currentBgm = stringToWstring("Bgm\\" + fileName);
        if (!PlaySound(currentBgm.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
            cerr << "Error: Unable to play " << fileName << endl;
        }
        else {
            cout << "Playing: " << fileName << endl;
        }
    }

    void stopBgm() {
        PlaySound(NULL, NULL, SND_PURGE);
        cout << "BGM stopped." << endl;
    }
};

GameBGM bgmManager; // BGM 관리 객체
SkillManager skill;

void playLobbyBgm() {
    int randomChoice = rand() % 2 + 1;
    bgmManager.playBgm("Lobby" + to_string(randomChoice) + ".wav");
}

void playBattleBgm(int stage) {
    string battleBgm;
    if (stage <= 10) battleBgm = "Battle_Bgm1.wav";
    else if (stage <= 20) battleBgm = "Battle_Bgm2.wav";
    else if (stage <= 30) battleBgm = "Battle_Bgm3.wav";
    else if (stage <= 40) battleBgm = "Battle_Bgm4.wav";
    else if (stage <= 50) battleBgm = "Battle_Bgm5.wav";
    else battleBgm = "Battle_Bgm6.wav";

    bgmManager.playBgm(battleBgm);
}

// 이름 유효성 검사 함수
bool isValidName(const string& name) {
    if (name.length() < 2 || name.length() > 8 || name.find(' ') != string::npos) {
        return false;
    }

    string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), tolower);
    if (lowerName.find("null") != string::npos) {
        return false;
    }

    for (unsigned char c : name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

// 전투 후 선택 메뉴
void ChoiceMenu(shared_ptr<Player> player, Shop& shop) {
    bool choiceMade = false;

    while (!choiceMade) {
        system("cls");
        cout << "\n=== 전투 후 선택 ===\n";
        cout << "1. 상점 이용\n2. 체력 회복\n선택: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            shop.openShop(player, skill); // 상점 이용
            choiceMade = true;
        }
        else if (choice == 2) {
            player->recoverHealth();
            cout << "체력을 회복했습니다!\n";
            choiceMade = true;
        }
        else {
            cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
        }
    }
    //playLobbyBgm();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // 랜덤 초기화
    string characterName;
    playLobbyBgm();

    // 캐릭터 이름 입력
    while (true) {
        cout << "\n\n묻지마 ! 용사 \n" << endl;
        Sleep(1000);
        print_img1();
        cout << "\n\n\n캐릭터 이름을 입력하세요 (2~8글자, 영어만 허용, 공백 및 특수문자 금지): ";
        cin >> characterName;

        if (isValidName(characterName)) {
            cout << "캐릭터 이름이 설정되었습니다: " << characterName << endl;
            break;
        }
        else {
            cout << "유효하지 않은 이름입니다. 다시 입력해주세요.\n";
        }
    }

    Player player(characterName);
    Shop shop;
    Battle battle(player);
    shared_ptr<Player> playerPointer = battle.getNowPlayer();

    // 게임 루프
    while (true) {
        playBattleBgm(battle.getStage()); // 스테이지별 BGM 재생
        battle.startBattle(); // 전투 시작
        playLobbyBgm();
        // 전투 후 선택
        ChoiceMenu(playerPointer, shop);

        // 종료 선택
        cout << "\n게임을 계속하시겠습니까? (1: 계속, 0: 종료): ";
        int continueGame;
        cin >> continueGame;

        if (continueGame == 0) {
            cout << "게임을 종료합니다!\n";
            break;
        }
    }
    bgmManager.stopBgm();
    return 0;
}
