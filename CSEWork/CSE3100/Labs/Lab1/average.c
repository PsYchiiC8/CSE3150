#include <stdio.h>

int main(void) {
    double x;
    double total = 0.0;
    double num = 0.0;
    while (scanf("%lf", &x) == 1) { // pay attention to %lf
        total = total + x;
        num += 1;
        double average = total / num;
        printf("Total=%lf Average=%lf\n", total, average);
    }

    return 0;
}