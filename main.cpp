#include <stdio.h>

int TypicallyCalc(int time) {
	return 1072 * time;
}

int RecursiveCalc(int time, int HourlyWage = 100) {
	if (time == 1) {
		return HourlyWage;
	}
	return (RecursiveCalc(time - 1, HourlyWage * 2 - 50));
}

void ComparisonWage(int time) {
	int Typically = TypicallyCalc(time);
	int Recursive = RecursiveCalc(time);
	printf("一般的な賃金 : %d\n", Typically);
	printf("再帰的な賃金 : %d\n", Recursive);
	if (Typically > Recursive) {
		printf("一般的な賃金体系");
	}
	else if (Typically < Recursive) {
		printf("再帰的な賃金体系");
	}
	else if (Typically == Recursive) {
		printf("同じ");
	}
}

int main() {
	ComparisonWage(9);

	return 0;
}





