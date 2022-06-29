#include "Weapon.h"

Weapon::Weapon()
{
	//  initialize base attributes
	std::cin >> baseDamage >> elementalDamage;
	//  setting the connections of sockets
	int connectionCount;
	std::cin >> connectionCount;
	for (int c = 0; c < connectionCount; c++)
	{
		char node1, node2;
		std::cin >> node1 >> node2;

		socketConnections[node1 - 'A'][node2 - 'A'] = true;
		socketConnections[node2 - 'A'][node1 - 'A'] = true;
	}
}

Weapon::~Weapon()
{
}

int Weapon::FindGemOnWeapon(const std::string& _GemName)
{
	for (int s = 0; s < 26; s++)
	{
		if (sockets[s] != NULL && sockets[s]->GetName() == _GemName)
		{
			return s;
		}
	}
	//	return -1 if the gem is not found
	return -1;
}

void Weapon::EquipGem(int _socketIdx, Gem* _gem)
{
	//TODO:...
	throw std::exception("This function is not implemented yet.");
}

int Weapon::CastSkill(const std::string& _skillGemName)
{
	//TODO:...
	throw std::exception("This function is not implemented yet.");
}

int Weapon::CalculateDamage(const DamageTerms& _terms)
{
	return (_terms.baseDamage + _terms.elementalDamage) * _terms.skillDamage * (1 + _terms.bonusDamage);
}
