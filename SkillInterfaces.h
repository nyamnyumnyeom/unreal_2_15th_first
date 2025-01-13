#ifndef SKILLINTERFACES_H
#define SKILLINTERFACES_H

#include "ISkill.h"
#include <algorithm> // for std::min
#include <iostream>

using namespace std;

// ������ ���� ��ų
class Skill1 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& monster, int skillLevel) override {
        int extraDamage = player.Damage() * skillLevel * 0.1;   // ������ ����: ���� x 10% ,  GetHealth �÷��̾� ������Ͽ� ���� ���� �Ǵ� �߰�
        cout << "������ ���� ��ų! ���Ϳ��� �߰� ������: " << extraDamage << "\n";
        monster.TakeDamage(extraDamage);     //TakeDamage ���� ������Ͽ� ���� ���� �Ǵ� �߰�
    }

    string GetName() const override {
        return "������ ���� ��ų";
    }

    string GetDescription() const override {
        return "���Ϳ��� �߰� �������� �����ϴ�. (���� x 10% �߰�)";
    }
};

// ü�� ȸ�� ��ų
class Skill2 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& /*monster*/, int skillLevel) override {
        double percentage = min(skillLevel * 0.05, 1.0); // �ִ� 100% ����
        int healAmount = player.GetMaxHP() * percentage; // ü�� ȸ�� , GetMaxHP �÷��̾� ������Ͽ� ���� ���� �Ǵ� �߰�
        cout << "ü�� ȸ�� ��ų �ߵ�! ȸ����: " << healAmount << " (" << percentage * 100 << "%)\n";
        player.Heal(healAmount);  //Heal �÷��̾� ������Ͽ� ���� ���� �Ǵ� �߰�
    }

    string GetName() const override {
        return "ü�� ȸ�� ��ų";
    }

    string GetDescription() const override {
        return "�÷��̾��� ü���� ȸ���մϴ�. (���� x 5% ȸ��)";
    }
};

// ���� ���� ��ų
class Skill3 : public ISkill {
public:
    void ApplyEffect(Player& player, Monster& monster, int skillLevel) override {
        double bonus = min(skillLevel * 0.05, 1.0); // �ִ� 100% ����
        monster.RewardBonus(bonus); // ���� ���� , RewardBonus ���� ������Ͽ� ���� ���� �Ǵ� �߰�
        cout << "���� ���� ��ų �ߵ�! ���� ������: " << bonus * 100 << "%\n";
    }

    string GetName() const override {
        return "���� ���� ��ų";
    }

    string GetDescription() const override {
        return "���� ����ġ ������ ������ŵ�ϴ�. (���� x 5% ����)";
    }
};

#endif // SKILLINTERFACES_H