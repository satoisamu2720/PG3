#include "Enemy.h"

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave
};
void Enemy::Update() {
	for (int i = 0; i < 3; i++) {
		(this->*spFuncTable[i])();
	}
}

void Enemy::Approach() {
	printf("Ú‹ß\n");
	static_cast<size_t>(EnemyState::Approach);
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Enemy::Shot() {
	printf("ËŒ‚\n");
	static_cast<size_t>(EnemyState::Shot);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Enemy::Leave() {
	printf("—£’E\n");
	static_cast<size_t>(EnemyState::Leave);
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

