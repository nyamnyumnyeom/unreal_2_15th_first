#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include "ISkill.h"
#include <unordered_map>
#include <vector>

using namespace std;

class SkillManager {
private:
    unordered_map<string, int> skillLevels; // 스킬 이름 -> 레벨
    vector<ISkill*> skills;                // 스킬 목록 (일반 포인터)

public:
    SkillManager();
    ~SkillManager(); // 스킬 객체 메모리 해제

    // 스킬 추가
    void AddSkill(ISkill* skill);

    // 스킬 보유 여부 확인
    bool HasSkill(const string& skillName) const;

    // 스킬 레벨 증가
    void LevelUpSkill(const string& skillName);

    // 스킬 사용
    void UseSkill(const string& skillName, Player& player, Monster& monster);

    // 모든 스킬 정보 출력
    void ShowSkills() const;

    // 스킬 목록 Getter (읽기 전용)
    const vector<ISkill*>& GetSkills() const;
};

#endif // SKILLMANAGER_H