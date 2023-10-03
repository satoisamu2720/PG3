#include <stdio.h>
template <typename T>
T minValue(int a, int b) {
    int min_value; /* Å¬’l */

    
    if (a < b) {
        min_value = a;
    } else {
        min_value = b;
    }

    return min_value;
}

int main() {
    printf("%d\n", minValue<int>(114, 514));
    printf("%f\n", minValue<float>(11.4f, 51.4f));
    printf("%f\n", minValue<double>(11.4f, 51.4f));
    printf("”šˆÈŠO‚Í‘ã“üo—ˆ‚Ü‚¹‚ñ\n", minValue<char>(11.4f, 51.4f));

    return 0;
}


//template <typename T>
//T add(T a, T b) {
//	return a + b;
//}
//
//template<>
//float add<float>(float a, float b) {
//	return a - b;
//}
//
//float add(float a, float b) {
//	return a * b;
//}




