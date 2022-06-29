#include "SupportGem.h"
#include "Weapon.h"

SupportGem::SupportGem() : Gem()
{
	std::cin >> bonusDamage;
}

SupportGem::~SupportGem()
{
}

DamageTerms& SupportGem::Affect(DamageTerms& _terms)
{
	//TODO:...
	throw std::exception("This function is not implemented yet.");
}
