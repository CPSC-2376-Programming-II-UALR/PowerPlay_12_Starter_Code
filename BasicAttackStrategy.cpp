#include "BasicAttackStrategy.h"
#include <iostream>
#include "Object.h"
#include "Player.h"
BasicAttackStrategy::BasicAttackStrategy (Player* owner)
	: iStrategy(owner, 'a', "(a)ttack")
{
}

void BasicAttackStrategy::execute(std::vector<std::unique_ptr<Object>>& objects) const 
{
	int monsterNum{ 1 };
	if (objects.size() > 2)
	{
		std::cout << "Which Monster: ";
		std::cin >> monsterNum;
	}
	if (monsterNum < 1)
	{
		monsterNum = 1;
	}
	else if (monsterNum >= objects.size())
	{
		monsterNum = (int)objects.size() - 1;
	}

	Object::nameOnly = true;
	system("CLS");
	std::cout << "**************FIGHT*****************" << std::endl;
	std::cout << *owner << " Attacks ";
	std::cout << *objects.at(monsterNum) << "!!\n";

	objects.at(monsterNum)->defend(objects.front()->attack());
}
