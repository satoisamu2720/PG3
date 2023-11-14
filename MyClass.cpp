#include "MyClass.h"

void (MyClass::* MyClass::spFuncTable[])() = {
	&MyClass::Func1,
	&MyClass::Func2
};
void MyClass::Initialize()
{
	//pFunc = &MyClass::TestFunc;
	(this->*spFuncTable[0])();
	(this->*spFuncTable[1])();
}
void MyClass::Func1() {
	printf("test\n");
}
void MyClass::Func2() {
	printf("test2");
}