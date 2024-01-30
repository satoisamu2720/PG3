#pragma once

#include "MyScene.h"
#include <memory>
#include <Novice.h>
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"


class GameManager {
private:
	std::unique_ptr<MyScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

	// キー入力結果を受け取る箱
	char keys_[256] = {0};
	char preKeys_[256] = {0};

public:
	GameManager();
	~GameManager();

	int Run();
};