#include "Enemy.h"
#include <Windows.h>
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave
};
void Enemy::Update() {
		(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::Approach() {
	printf("Ú‹ß\n");
	Sleep(3 * 600);
	phase_ = EnemyState::Shot;
}

void Enemy::Shot() {
	printf("ËŒ‚\n");
	Sleep(3 * 600);
	phase_ = EnemyState::Leave;
}

void Enemy::Leave() {
	printf("—£’E\n");
	count = true;
}

