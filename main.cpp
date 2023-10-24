#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>

std::random_device seed_Gen;
std::mt19937 mtrand(seed_Gen());

typedef int (*Pfunc)();

int Dice() {
	return std::uniform_int_distribution<int>(1, 6)(seed_Gen);
}

void DiceResult(int diceNumber) {
	//‹ô”
	if (diceNumber % 2 == 0) {
		printf("Œ‹‰Ê@’š\n");
	}
	// Šï”
	if (diceNumber % 2 == 1) {
		printf("Œ‹‰Ê@”¼\n");
	}
}

int SetTimeOut(Pfunc collback, int second) {
	std::this_thread::sleep_for(std::chrono::seconds(second));
	return collback();

}

int main() {

	Pfunc p;
	p = Dice;
	int Result;
	int Answer;

	while (true) {

		printf("1:”¼@2:’š\n");
		std::cin >> Answer;
		if (Answer == 0) {
			break;
		}
		Result = SetTimeOut(p, 3);
		printf("“š‚¦ : %d\n", Result);
		DiceResult(Result);
		if (Result % 2 == 0 && Answer == 2) {
			printf("Ÿ‚¿\n");
		}
		else if (Result % 2 == 1 && Answer == 1) {
			printf("Ÿ‚¿\n");
		}
		else {
			printf("•‰‚¯\n");
		}

	}

	return 0;
}