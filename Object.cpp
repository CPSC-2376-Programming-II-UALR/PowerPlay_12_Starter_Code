#include <random>
#include <iostream>
#include "Object.h"
std::random_device Object::seed;
std::default_random_engine Object::engine(seed());
bool Object::nameOnly{ false };

Object::Object(Type name, int strength, int health, int level) : name{ name }, strength{ strength }, health{ health }, level{ level }
{
}


void Object::print(std::ostream& o) const
{
	switch (getName())
	{
	case Object::Type::player:
		std::cout << "Player";
		break;
	case Object::Type::slime:
		std::cout << "Slime";
		break;
	case Object::Type::orc:
		std::cout << "Orc";
		break;
	case Object::Type::sprite:
		std::cout << "Sprite";
		break;
	case Object::Type::dragon:
		std::cout << "Dragon";
		break;
	}

}

void Object::heal(int amount)
{
	std::cout << *this << " is healed by " << amount << "hp!" << std::endl;
	health += amount;
}

void Object::scare()
{
	condition.insert_or_assign(Object::StatusEffect::afraid, true);
}

void Object::weaken(int amount)
{
	strength -= amount;
}

int Object::getStrength() const
{
	return strength;
}


bool Object::isDead()
{
	return health <= 0;
}

Object::Type Object::getName() const
{
	return name;
}

int Object::getLevel() const
{
	return level;
}

int Object::getHealth() const
{
	return health;
}

int Object::damageDone(int modification) const
{
	Object::nameOnly = true;
	int potentialDamage{ strength + modification };
	std::normal_distribution<double> damageDealt(potentialDamage, 2.0);
	std::cout << *this << " deals ";
	return std::max(1, (int)damageDealt(engine));
}

int Object::damageTaken(int damageDone, int AC)
{
	Object::nameOnly = true;
	std::normal_distribution<double> defense(AC, 1.0 / level);
	damageDone = std::max(0, damageDone - (int)defense(engine));

	std::cout << damageDone << " damage to ";

	std::cout << *this << "!!!" << std::endl;
	health -= damageDone;
	return damageDone;
}
std::ostream& operator<< (std::ostream& o, const Object& src)
{
	src.print(o);
	return o;
}
std::ostream& operator<<(std::ostream& o, const std::unique_ptr<Object>& src)
{
	src->print(o);
	return o;
}
