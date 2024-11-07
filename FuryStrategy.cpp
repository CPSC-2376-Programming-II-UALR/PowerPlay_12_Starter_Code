#include "FuryStrategy.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "Object.h"
#include "Player.h"
FuryStrategy::FuryStrategy(Player* owner)
	:iStrategy(owner, 'f', "(f)ury")
{
}

void FuryStrategy::execute(std::vector<std::unique_ptr<Object>>& objects) const 
{
	std::cout << "Your fury blows through the front lines of the enemies!" << std::endl;
	
	//for (int i{ std::min(2, (int)objects.size() - 1) }; i > 0; i--)
	std::for_each(objects.begin() + 1,
		objects.begin() + std::min(3, (int)objects.size()), 
		[&](std::unique_ptr<Object>& object)
		{
			object->defend(owner->attack());
			object->defend(owner->attack());
			object->scare();
		});
	{
		
	}

	std::cout << "The fury has left you weakend, your strength drops " << owner->getStrength() << " --> ";
	owner->weaken(1);
	std::cout << owner->getStrength() << std::endl;
	system("PAUSE");
	system("CLS");
}
