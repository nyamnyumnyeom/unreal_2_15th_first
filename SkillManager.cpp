#include "SkillManager.h"
#include <iostream>

SkillManager::SkillManager() {
    // �ʱ� ��ų ���� ����
}

void SkillManager::AddSkill(unique_ptr<ISkill> skill) {
    string name = skill->GetName();
    skills.push_back(move(skill));
    skillLevels[name] = 0; // �ʱ� ���� ����
}

void SkillManager::LevelUpSkill(const string& skillName) {
    if (skillLevels.find(skillName) != skillLevels.end()) {
        skillLevels[skillName]++;
        cout << skillName << "�� ������ �����߽��ϴ�! ���� ����: " << skillLevels[skillName] << "\n";
    }
    else {
        cout << "�ش� ��ų�� ã�� �� �����ϴ�.\n";
    }
}

void SkillManager::UseSkill(const string& skillName, Player& player, Monster& monster) {
    for (const auto& skill : skills) {
        if (skill->GetName() == skillName) {
            int level = skillLevels[skillName];
            if (level > 0) {
                skill->ApplyEffect(player, monster, level);
            }
            else {
                cout << skillName << " ��ų�� ������ 0�Դϴ�. ��ų�� ����� �� �����ϴ�.\n";
            }
            return;
        }
    }
    cout << "�ش� ��ų�� ã�� �� �����ϴ�.\n";
}

void SkillManager::ShowSkills() const {
    cout << "=== ��ų ��� ===\n";
    for (const auto& skill : skills) {
        string name = skill->GetName();
        cout << name << " (����: " << skillLevels.at(name) << ")\n";
        cout << "����: " << skill->GetDescription() << "\n";
    }
}