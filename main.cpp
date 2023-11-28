#include "Ant.h"
#include "Elephantrs.h"
#include "Creature.h"

int main() {
	Creature* Charactor[2];
	Charactor[0] = new Ant();
	Charactor[1] = new Elephantrs();

	Charactor[0]->Size();
	Charactor[1]->Size();

	return 0;
}