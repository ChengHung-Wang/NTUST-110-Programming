#pragma once
#include <string>
#include <iostream>

//	forward declaration
struct DamageTerms;

//	The base class of SkillGem & SupportGem
class Gem
{
public:
	Gem();
	~Gem();
	virtual DamageTerms& Affect(DamageTerms& _terms) = 0;
	const std::string GetName() { return name; }
protected:
	std::string name;
	int elementalDamage;
};
