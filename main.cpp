#include <stdio.h>


int Recursive(int h, int j, int m) {

	if (h <= 0) {
		//���������������ꍇ
		return j;
	}

	return Recursive(h - 1, j += m, m * 2 - 50);

}



int TypicallyCalc(int time) {
	return 1072 * time;

}

int RecursiveCalc(int time,int j, int HourlyWage) {

	/*if (time == 1) {
		return HourlyWage;
	}*/
	if (time <= 0) {
		//���������������ꍇ
		return j;
	}
	return (RecursiveCalc(time - 1,j+= HourlyWage, HourlyWage * 2 - 50));
}

void ComparisonWage(int time, int j, int HourlyWage) {
	int Typically = TypicallyCalc(time);
	int Recursive = RecursiveCalc(time,j, HourlyWage);
	printf("\n��ʓI�Ȓ��� : %d\n", Typically);
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
	

	ComparisonWage(4,0,100);

	return 0;

}





