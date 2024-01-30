#pragma once

#include "MyScene.h"
#include <Novice.h>

class StageScene : public MyScene {

public:
	void Init() override;
	void Update() override;
	void Draw() override;
};