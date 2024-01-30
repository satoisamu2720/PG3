#include "ClearScene.h"
void ClearScene::Init() {}

void ClearScene::Update() {
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() { Novice::ScreenPrintf(640, 360, "Clear"); }