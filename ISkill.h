#ifndef ISKILL_H
#define ISKILL_H

#include "Player.h"
#include "Monster.h"
#include <string>

using namespace std;

// 스킬 인터페이스
class ISkill {
public:
    virtual ~ISkill() = default;

    // 스킬 효과를 적용하는 메서드
    virtual void ApplyEffect(Player& player, Monster& monster, int skillLevel) = 0;

    // 스킬 이름 반환
    virtual string GetName() const = 0;

    // 스킬 설명 반환
    virtual string GetDescription() const = 0;
};

#endif // ISKILL_H