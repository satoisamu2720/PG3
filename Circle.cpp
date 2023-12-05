#include "Circle.h"
void Circle::size() {
	area = radius * radius * 3.14f;
}

void Circle::draw() {
	printf("%f\n", area);
}