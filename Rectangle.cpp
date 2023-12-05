#include "Rectangle.h"
void Rectangle::size() {
	area = (radius * 2) * (radius * 2);
}

void Rectangle::draw() {
	printf("%f\n", area);
}