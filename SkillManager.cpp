#include "SkillManager.h"
#include <iostream>

SkillManager::SkillManager() {
    // 초기 스킬 레벨 설정
}

void SkillManager::AddSkill(unique_ptr<ISkill> skill) {
    string name = skill->GetName();
    skills.push_back(move(skill));
    skillLevels[name] = 0; // 초기 레벨 설정
}

void SkillManager::LevelUpSkill(const string& skillName) {
    if (skillLevels.find(skillName) != skillLevels.end()) {
        skillLevels[skillName]++;
        cout << skillName << "의 레벨이 증가했습니다! 현재 레벨: " << skillLevels[skillName] << "\n";
    }
    else {
        cout << "해당 스킬을 찾을 수 없습니다.\n";
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
                cout << skillName << " 스킬의 레벨이 0입니다. 스킬을 사용할 수 없습니다.\n";
            }
            return;
        }
    }
    cout << "해당 스킬을 찾을 수 없습니다.\n";
}

void SkillManager::ShowSkills() const {
    cout << "=== 스킬 목록 ===\n";
    for (const auto& skill : skills) {
        string name = skill->GetName();
        cout << name << " (레벨: " << skillLevels.at(name) << ")\n";
        cout << "설명: " << skill->GetDescription() << "\n";
    }
}