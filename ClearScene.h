#pragma once

#include "MyScene.h"
#include <Novice.h>

class ClearScene : public MyScene {

public:
	void Init() override;
	void Update() override;
	void Draw() override;
};