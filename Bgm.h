#pragma once
#ifndef BGM_H
#define BGM_H

#include <string>
#include <atomic>
#include <Windows.h>

class BgmManager {
private:
    std::atomic<bool> isPlaying{ false };
    std::wstring currentBgm;

    // 문자열을 wstring으로 변환
    std::wstring stringToWstring(const std::string& str);

public:
    BgmManager() = default;
    ~BgmManager();

    // BGM 재생
    void playBgm(const std::string& filePath, bool loop = true);

    // BGM 정지
    void stopBgm();
};

#endif // BGM_H
