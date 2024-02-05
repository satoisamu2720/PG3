#pragma once
#include "Player.h"

class Player;

class ICommand {
public:
	virtual ~ICommand();
	virtual void Exec(Player& player) = 0;
};

class RightCommand : public ICommand {
public:
	virtual void Exec(Player& player) override;
};
class LeftCommand : public ICommand {
public:
	virtual void Exec(Player& player) override;
};
