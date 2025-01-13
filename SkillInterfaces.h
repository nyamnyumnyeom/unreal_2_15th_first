#ifndef SKILLINTERFACES_H
#define SKILLINTERFACES_H

#include "ISkill.h"
#include <algorithm> // for std::min
#include <iostream>

using namespace std;

// 데미지 증가 스킬
class Skill1 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& monster, int skillLevel) override {
        int extraDamage = player.Damage() * skillLevel * 0.1;   // 데미지 증가: 레벨 x 10% ,  GetHealth 플레이어 헤더파일에 따라 수정 또는 추가
        cout << "데미지 증가 스킬! 몬스터에게 추가 데미지: " << extraDamage << "\n";
        monster.TakeDamage(extraDamage);     //TakeDamage 몬스터 헤더파일에 따라 수정 또는 추가
    }

    string GetName() const override {
        return "데미지 증가 스킬";
    }

    string GetDescription() const override {
        return "몬스터에게 추가 데미지를 입힙니다. (레벨 x 10% 추가)";
    }
};

// 체력 회복 스킬
class Skill2 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& /*monster*/, int skillLevel) override {
        double percentage = min(skillLevel * 0.05, 1.0); // 최대 100% 제한
        int healAmount = player.GetMaxHP() * percentage; // 체력 회복 , GetMaxHP 플레이어 헤더파일에 따라 수정 또는 추가
        cout << "체력 회복 스킬 발동! 회복량: " << healAmount << " (" << percentage * 100 << "%)\n";
        player.Heal(healAmount);  //Heal 플레이어 헤더파일에 따라 수정 또는 추가
    }

    string GetName() const override {
        return "체력 회복 스킬";
    }

    string GetDescription() const override {
        return "플레이어의 체력을 회복합니다. (레벨 x 5% 회복)";
    }
};

// 보상 증가 스킬
class Skill3 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& monster, int skillLevel) override {
        double bonus = min(skillLevel * 0.05, 1.0); // 최대 100% 제한
        monster.RewardBonus(bonus); // 보상 증가 , RewardBonus 몬스터 헤더파일에 따라 수정 또는 추가
        cout << "보상 증가 스킬 발동! 보상 증가율: " << bonus * 100 << "%\n";
    }

    string GetName() const override {
        return "보상 증가 스킬";
    }

    string GetDescription() const override {
        return "골드와 경험치 보상을 증가시킵니다. (레벨 x 5% 증가)";
    }
};

#endif // SKILLINTERFACES_H