#pragma once
#include "Vector2.h"

class Player {
private:
	Vector2 pos_;
	float speed_;

public:
	Player();

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();
};
