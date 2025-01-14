#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include "ISkill.h"
#include <unordered_map>
#include <vector>
#include <memory> // for unique_ptr

using namespace std;

class SkillManager {
private:
    unordered_map<string, int> skillLevels; // ��ų �̸� -> ����
    vector<unique_ptr<ISkill>> skills;     // ��ų ���

public:
    SkillManager();

    // ��ų �߰�
    void AddSkill(unique_ptr<ISkill> skill);

    // ��ų ���� ���� Ȯ��     ****** �߰� *******
    bool HasSkill(const string& skillName) const;

    // ��ų ���� ����
    void LevelUpSkill(const string& skillName);

    // ��ų ���
    void UseSkill(const string& skillName, Player& player, Monster& monster);

    // ��� ��ų ���� ���
    void ShowSkills() const;
};

#endif // SKILLMANAGER_H
