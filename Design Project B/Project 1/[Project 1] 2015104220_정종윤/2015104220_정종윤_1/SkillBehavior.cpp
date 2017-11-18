#include "SkillBehavior.h"	

SkillBehavior::SkillBehavior()
{

}

SkillBehavior::~SkillBehavior()
{

}

int SkillBehavior::executeTurn(Pokemon* subjet, Pokemon* target)
{
	subjet->skill(subjet, target);
	subjet->skill_cnt -= 1;
	return 0;
}