#include "Enemy.h"

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
	std::this_thread::sleep_for(std::chrono::seconds(2));
	phase_ = EnemyState::Shot;
}

void Enemy::Shot() {
	printf("ËŒ‚\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
	phase_ = EnemyState::Leave;
}

void Enemy::Leave() {
	printf("—£’E\n");
	count = true;
}

