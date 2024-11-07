#pragma once
#include <string>
#include <vector>
#include <memory>
class Player;
class Object;
class iStrategy
{
public:
	iStrategy() = delete;
	iStrategy(Player* owner, char commandToActivate, std::string actionName);

	virtual void execute(std::vector<std::unique_ptr<Object>>& objects) const =0;

	const char commandToActivate{ ' ' };
	const std::string actionName;
	Player* owner{ nullptr };

};