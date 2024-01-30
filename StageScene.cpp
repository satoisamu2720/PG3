#include "StageScene.h"
void StageScene::Init() {}

void StageScene::Update() {
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw() { Novice::ScreenPrintf(640, 360, "Stage"); }