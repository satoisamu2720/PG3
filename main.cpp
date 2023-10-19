#include <stdio.h>


int Recursive(int h, int j, int m) {

	if (h <= 0) {
		//処理が成功した場合
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
		//処理が成功した場合
		return j;
	}
	return (RecursiveCalc(time - 1,j+= HourlyWage, HourlyWage * 2 - 50));
}

void ComparisonWage(int time, int j, int HourlyWage) {
	int Typically = TypicallyCalc(time);
	int Recursive = RecursiveCalc(time,j, HourlyWage);
	printf("\n一般的な賃金 : %d\n", Typically);
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
	

	ComparisonWage(4,0,100);

	return 0;

}





