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
	printf("�ڋ�\n");
	Sleep(3 * 600);
	phase_ = EnemyState::Shot;
}

void Enemy::Shot() {
	printf("�ˌ�\n");
	Sleep(3 * 600);
	phase_ = EnemyState::Leave;
}

void Enemy::Leave() {
	printf("���E\n");
	count = true;
}

