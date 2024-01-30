#include "TitleScene.h"

void TitleScene::Init() {

}

void TitleScene::Update() {
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() { Novice::ScreenPrintf(640, 360, "Title"); }
