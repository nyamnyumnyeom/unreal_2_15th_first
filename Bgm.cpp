#include "Bgm.h"
#include <iostream>

#pragma comment(lib, "winmm.lib")

// ���ڿ��� wstring���� ��ȯ
std::wstring BgmManager::stringToWstring(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

// BgmManager �Ҹ���
BgmManager::~BgmManager() {
    stopBgm(); // �Ҹ� �� BGM ����
}

// BGM ���
void BgmManager::playBgm(const std::string& filePath, bool loop) {
    stopBgm();
    currentBgm = stringToWstring(filePath);
    isPlaying = true;

    std::cout << "����� : " << filePath << std::endl;

    if (!PlaySound(currentBgm.c_str(), NULL, SND_FILENAME | SND_ASYNC | (loop ? SND_LOOP : 0))) {
        std::cerr << "����Ұ�!!!!!!" << filePath << std::endl;
        isPlaying = false;
    }
}

// BGM ����
void BgmManager::stopBgm() {
    if (isPlaying) {
        PlaySound(NULL, NULL, SND_PURGE);
        isPlaying = false;
    }
}
