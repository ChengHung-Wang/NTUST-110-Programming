#include "SkillGem.h"
#include "Weapon.h"

SkillGem::SkillGem() : Gem()
{
	std::cin >> skillDamage;
}

SkillGem::~SkillGem()
{
}

DamageTerms& SkillGem::Affect(DamageTerms& _terms)
{
	//TODO:...
	throw std::exception("This function is not implemented yet.");
}
