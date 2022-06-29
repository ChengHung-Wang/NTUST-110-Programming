#pragma once
#include "Gem.h"

class SkillGem : public Gem
{
public:
	SkillGem();
	~SkillGem();
	DamageTerms& Affect(DamageTerms& _terms);

private:
	int skillDamage;
};
