#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>
//#include "MyClass.h"
#include "Enemy.h"

//std::random_device seed_Gen;
//std::mt19937 mtrand(seed_Gen());

int main() {
	Enemy* enemy_ = new Enemy();

while (enemy_->GetCount() == false) {
		enemy_->Update();
	}



	return 0;
}