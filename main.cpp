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
	printf("��ʓI�Ȓ��� : %d\n", Typically);
	printf("�ċA�I�Ȓ��� : %d\n", Recursive);
	if (Typically > Recursive) {
		printf("��ʓI�Ȓ����̌n");
	}
	else if (Typically < Recursive) {
		printf("�ċA�I�Ȓ����̌n");
	}
	else if (Typically == Recursive) {
		printf("����");
	}
}

int main() {
	ComparisonWage(9);

	return 0;
}





