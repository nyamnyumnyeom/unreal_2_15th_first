#include "Bgm.h"
#include <iostream>

#pragma comment(lib, "winmm.lib")

// 문자열을 wstring으로 변환
std::wstring BgmManager::stringToWstring(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

// BgmManager 소멸자
BgmManager::~BgmManager() {
    stopBgm(); // 소멸 시 BGM 정지
}

// BGM 재생
void BgmManager::playBgm(const std::string& filePath, bool loop) {
    stopBgm();
    currentBgm = stringToWstring(filePath);
    isPlaying = true;

    std::cout << "재생중 : " << filePath << std::endl;

    if (!PlaySound(currentBgm.c_str(), NULL, SND_FILENAME | SND_ASYNC | (loop ? SND_LOOP : 0))) {
        std::cerr << "재생불가!!!!!!" << filePath << std::endl;
        isPlaying = false;
    }
}

// BGM 정지
void BgmManager::stopBgm() {
    if (isPlaying) {
        PlaySound(NULL, NULL, SND_PURGE);
        isPlaying = false;
    }
}
