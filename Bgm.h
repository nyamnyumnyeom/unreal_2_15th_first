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

    // ���ڿ��� wstring���� ��ȯ
    std::wstring stringToWstring(const std::string& str);

public:
    BgmManager() = default;
    ~BgmManager();

    // BGM ���
    void playBgm(const std::string& filePath, bool loop = true);

    // BGM ����
    void stopBgm();
};

#endif // BGM_H
