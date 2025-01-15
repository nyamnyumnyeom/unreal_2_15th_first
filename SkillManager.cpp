#include "SkillManager.h"
#include <iostream>
#include <algorithm> // for std::find_if

SkillManager::SkillManager() {}

SkillManager::~SkillManager() {
    for (auto skill : skills) {
        delete skill; // �������� �Ҵ�� ��ų ��ü ����
    }
    skills.clear();
}

void SkillManager::AddSkill(ISkill* skill) {
    const string& skillName = skill->GetName();
    if (!HasSkill(skillName)) {
        skills.push_back(skill);
        skillLevels[skillName] = 1; // �ʱ� ���� ����
        cout << skillName << " ��ų�� �߰��Ǿ����ϴ�. (���� 1)\n";
    }
    else {
        cout << skillName << " ��ų�� �̹� �����մϴ�.\n";
        delete skill; // �ߺ��� ��ų ��ü�� ��� ����
    }
}

bool SkillManager::HasSkill(const string& skillName) const {
    return any_of(skills.begin(), skills.end(),
        [&skillName](const ISkill* skill) {
            return skill->GetName() == skillName;
        });
}

void SkillManager::LevelUpSkill(const string& skillName) {
    if (HasSkill(skillName)) {
        skillLevels[skillName]++;
        cout << skillName << " ��ų�� ������ �����߽��ϴ�! ���� ����: " << skillLevels[skillName] << "\n";
    }
    else {
        cout << skillName << " ��ų�� �����ϴ�.\n";
    }
}

void SkillManager::UseSkill(const string& skillName, Player& player, Monster& monster) {
    auto it = find_if(skills.begin(), skills.end(),
        [&skillName](const ISkill* skill) {
            return skill->GetName() == skillName;
        });

    if (it != skills.end()) {
        int skillLevel = skillLevels[skillName];
        (*it)->ApplyEffect(player, monster, skillLevel);
    }
    else {
        cout << skillName << " ��ų�� �����ϴ�.\n";
    }
}

void SkillManager::ShowSkills() const {
    cout << "=== ��ų ��� ===\n";
    for (const auto skill : skills) {
        const string& skillName = skill->GetName();
        cout << skillName << " (����: " << skillLevels.at(skillName) << ")\n";
        cout << "����: " << skill->GetDescription() << "\n";
    }
}

const vector<ISkill*>& SkillManager::GetSkills() const {
    return skills;
}