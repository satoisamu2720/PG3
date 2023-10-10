#include <stdio.h>

template<typename T1, typename T2>

T1 Min(T1 a, T2 b) {
    if (static_cast<T1>(a) <= static_cast<T2>(b)) {
        return static_cast<T1>(a);
    }
    else {
        return static_cast<T1>(b);
    }
}

template <>
char Min<char>(char a, char b) {
    return printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
}

int main(void) {
    printf("%d\n", Min<int, int>(114, 514));
    printf("%f\n", Min<float, float>(11.4f, 51.4f));
    printf("%lf\n", Min<double, double>(11.4f, 51.4f));
    printf("%c\n", Min<char, char>(11.4f, 51.4f));

    return 0;
}











