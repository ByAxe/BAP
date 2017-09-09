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
    double top, bottom, minus, result, tg2;

    top = pow((8 + pow(fabs(x - y), 2) + 1), 1 / 3);

    bottom = x * x + y * y + 2;

    tg2 = (1 - cos(2 * z)) / (1 + cos(2 * z));
    minus = exp(fabs(x - y)) * pow(tg2 + 1, x);

    result = (top / bottom) - minus;

    return result;
}

/**
 *
 * @return
 */
boolean testCalculation() {
    double x = -4.5;
    double y = 0.75e-4;
    double z = 0.845e+2;

    double expected = -55.6848;
    double actual = calculate(x, y, z);

    printf("Expected: %lf\nActual: %lf\n", expected, actual);

    return (expected == actual)
           || (expected - actual <= 0.1)
           || (actual - expected <= 0.1);
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
    printf("\nTest passed: %s", result ? "Yes" : "No");

    return 0;
}

