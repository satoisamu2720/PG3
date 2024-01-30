#include "MyScene.h"
int MyScene::sceneNo = TITLE;

MyScene::~MyScene() {}

int MyScene::GetScenNo() { return sceneNo; }

void MyScene::SetKeys(char* keys, char* preKeys) { 
	keys_ = keys;
	preKeys_ = preKeys;
}
