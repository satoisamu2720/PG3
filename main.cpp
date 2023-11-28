#include "Base.h"
#include <stdio.h>

int main() {

	Pair<int, int> calc1(100, 200);
	Pair<int, float> calc2(100, 200.0f);
	Pair<int, double> calc3(100, 200.0f);
	Pair<float, float> calc4(100.0f, 200.0f);
	Pair<float, double> calc5(100.0f, 200.0f);
	Pair<double, double> calc6(100.0f, 200.0f);

	printf(" %d\n", calc1.Min<int>());
	printf(" %f\n", calc2.Min<float>());
	printf(" %lf\n", calc3.Min<double>());
	printf(" %f\n", calc4.Min<float>());
	printf(" %lf\n", calc5.Min<double>());
	printf(" %lf\n", calc6.Min<double>());

}