#ifndef SKILLMANAGER_H
#define SKILLMANAGER_H

#include "ISkill.h"
#include <unordered_map>
#include <vector>

using namespace std;

class SkillManager {
private:
    unordered_map<string, int> skillLevels; // ��ų �̸� -> ����
    vector<ISkill*> skills;                // ��ų ��� (�Ϲ� ������)

public:
    SkillManager();
    ~SkillManager(); // ��ų ��ü �޸� ����

    // ��ų �߰�
    void AddSkill(ISkill* skill);

    // ��ų ���� ���� Ȯ��
    bool HasSkill(const string& skillName) const;

    // ��ų ���� ����
    void LevelUpSkill(const string& skillName);

    // ��ų ���
    void UseSkill(const string& skillName, Player& player, Monster& monster);

    // ��� ��ų ���� ���
    void ShowSkills() const;

    // ��ų ��� Getter (�б� ����)
    const vector<ISkill*>& GetSkills() const;
};

#endif // SKILLMANAGER_H