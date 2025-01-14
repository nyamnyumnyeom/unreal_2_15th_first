#include "Boss.h"
#include <iostream>

Boss::Boss() :Monster("Boss", 300000, 15000) {

}

void Boss::bossSkill() {
	std::cout << "Boss skill \n";
	//보스스킬 구현 예정   
}
