#pragma once
#include <stdio.h>
#include <thread>
#include <chrono>

enum class EnemyState {
	Approach,
	Shot,
	Leave
};

class Enemy {
public:

	void Update();

	void Approach();

	void Leave();

	void Shot();

	bool GetCount() { return count; }

private:

	static void (Enemy::* spFuncTable[])();
	size_t state;
	EnemyState phase_ = EnemyState::Approach;
	bool count = false;
};

