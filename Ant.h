#pragma once
#include "Creature.h"
#include <stdio.h>

class Ant : public Creature
{
public:
	Ant();
	~Ant();

	void Size()override;

private:
};
