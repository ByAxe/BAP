#include <stdio.h>
#include <math.h>
#include <jmorecfg.h>

#define INACCURACY 0.1

boolean assertEquals(double actual, double expected);

/**
 * Основные рассчеты по заданной формуле
 *
 * @param x первая переменная
 * @param y вторая переменная
 * @param z третья переменная
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
 * Тест
 * Сверяет верность рассчетов метода calculate
 *
 * @return верно, или не верно
 */
boolean testCalculation() {
    double x = -4.5;
    double y = 0.75e-4;
    double z = 0.845e+2;

    double expected = -55.6848;
    double actual = calculate(x, y, z);

    printf("Expected: %lf\nActual: %lf\n", expected, actual);

    return assertEquals(actual, expected);
}


void test() {
    printf("\n\n********TEST*********\n");
    boolean result = testCalculation();
    printf("\nTest passed: %s", result ? "Yes" : "No");
    printf("\n********TEST*********\n\n");
}

/**
 * Точка входа в программу.
 * 1) Ввод данных пользователем
 * 2) Тест в конце, для удостоверения что все работает хорошо
 *
 * @return
 */
int main() {

    // 1)
    double x, y, z;
    puts("\n\t x,y,z = ");
    scanf("%lf %lf %lf", &x, &y, &z);
    double result = calculate(x, y, z);
    printf("Result: %lf", result);

    // 2)
    test();

    return 0;
}

/**
 * Убеждаемся в равенстве ожидаемого и полученного значения
 * С учетом погрешности рассчетов с использованием double
 *
 * @param actual
 * @param expected
 * @return
 */
boolean assertEquals(double actual, double expected) {
    return (expected == actual)
           || (expected - actual <= INACCURACY)
           || (actual - expected <= INACCURACY);
}
