#ifndef ISKILL_H
#define ISKILL_H

#include "Player.h"
#include "Monster.h"
#include <string>

using namespace std;

// ��ų �������̽�
class ISkill {
public:
    virtual ~ISkill() = default;

    // ��ų ȿ���� �����ϴ� �޼���
    virtual void ApplyEffect(Player& player, Monster& monster, int skillLevel) = 0;

    // ��ų �̸� ��ȯ
    virtual string GetName() const = 0;

    // ��ų ���� ��ȯ
    virtual string GetDescription() const = 0;
};

#endif // ISKILL_H