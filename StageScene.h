#pragma once

#include "MyScene.h"
#include <Novice.h>

class StageScene : public MyScene {

public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};