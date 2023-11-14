#pragma once
#include <stdio.h>
#include "Enemy.h"
class MyClass
{
public:
	//自作メンバ関数
	void Func1();
	void Func2();
	void Initialize();
	//void TestFunc();
private:
	//メンバ関数ポインタ
	//void (MyClass::* pFunc)();
	static void (MyClass::* spFuncTable[])();

};

