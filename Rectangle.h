#pragma once

#include "Base.h"
#include <stdio.h>

class Rectangle : public IShape
{
public:

	Rectangle(float rad) { radius = rad; }

	void size()override;

	void draw()override;

private:

	float area = 0.0f;
	float radius = 0.0f;

};

