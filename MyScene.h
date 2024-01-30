#pragma once
enum Scene { TITLE, STAGE, CLEAR,SceneMax };

class MyScene {
protected:
	static int sceneNo;
	char* keys_;
	char* preKeys_;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~MyScene();

	int GetScenNo();

	void SetKeys(char* keys, char* preKeys);
};
