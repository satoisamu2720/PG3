#pragma once
#include <stdio.h>
#include "Enemy.h"
class MyClass
{
public:
	//���상���o�֐�
	void Func1();
	void Func2();
	void Initialize();
	//void TestFunc();
private:
	//�����o�֐��|�C���^
	//void (MyClass::* pFunc)();
	static void (MyClass::* spFuncTable[])();

};

