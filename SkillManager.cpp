#include "SkillManager.h"
#include <iostream>
#include <algorithm> // for std::find_if

SkillManager::SkillManager() {}

SkillManager::~SkillManager() {
    for (auto skill : skills) {
        delete skill; // 동적으로 할당된 스킬 객체 해제
    }
    skills.clear();
}

void SkillManager::AddSkill(ISkill* skill) {
    const string& skillName = skill->GetName();
    if (!HasSkill(skillName)) {
        skills.push_back(skill);
        skillLevels[skillName] = 1; // 초기 레벨 설정
        cout << skillName << " 스킬이 추가되었습니다. (레벨 1)\n";
    }
    else {
        cout << skillName << " 스킬은 이미 존재합니다.\n";
        delete skill; // 중복된 스킬 객체를 즉시 해제
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
        cout << skillName << " 스킬의 레벨이 증가했습니다! 현재 레벨: " << skillLevels[skillName] << "\n";
    }
    else {
        cout << skillName << " 스킬이 없습니다.\n";
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
        cout << skillName << " 스킬이 없습니다.\n";
    }
}

void SkillManager::ShowSkills() const {
    cout << "=== 스킬 목록 ===\n";
    for (const auto skill : skills) {
        const string& skillName = skill->GetName();
        cout << skillName << " (레벨: " << skillLevels.at(skillName) << ")\n";
        cout << "설명: " << skill->GetDescription() << "\n";
    }
}

const vector<ISkill*>& SkillManager::GetSkills() const {
    return skills;
}