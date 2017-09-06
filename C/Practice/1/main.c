#include <stdio.h>
#include <math.h>
#include <jmorecfg.h>

/**
 *
 * @param x
 * @param y
 * @param z
 * @return
 */
double calculate(double x, double y, double z) {
    double part1, part2, part3, result, tg;

    part1 = pow((8 + pow(fabs(x - y), 2) + 1), 1 / 3);
    part2 = pow(x, 2) + pow(y, 2) + 2;

    tg = 1 / ((1 + cos(2 * z)) / 2);
    part3 = exp(fabs(x - y)) * pow(tg + 1, x);

    result = (part1 / part2) - part3;

    return result;
}

/**
 *
 * @return
 */
boolean testCalculation() {
    double x = -4.5;
    double y = 0.75 * pow(10, -4);
    double z = 0.854 * pow(10, 2);

    double expected = -55.6848;
    double actual = calculate(x, y, z);

    printf("Expected: %lf\nActual: %lf\n", expected, actual);

    return expected == actual;
}

/**
 *
 * @return
 */
int main() {

//    double x, y, z;
//    puts("\n\t x,y,z = ");
//    scanf("%lf %lf %lf", &x, &y, &z);

    boolean result = testCalculation();
    printf("Test passed: %s", result ? "Yes" : "No");

    return 0;
}

