#include <stdio.h>
#include <jmorecfg.h>
#include <math.h>

#define INACCURACY 0.001

void test();

boolean testCalculation();

boolean testCalculation_firstBranch();

boolean testCalculation_secondBranch();

boolean assertEquals(double actual, double expected);

double calculate(double x, double y);

/**
 * Точка входа в программу.
 * 1) Ввод данных пользователем
 * 2) Тест в конце, для удостоверения что все работает хорошо
 *
 * @return
 */
int main() {

    // 1)
    double x, y;
    puts("\n\t x,y = ");
    scanf("%lf %lf", &x, &y);
    double result = calculate(x, y);
    printf("Result: %lf", result);

    // 2)
    test();

    return 0;
}

/**
 * Основные рассчеты по заданной формуле
 *
 * @param x первая переменная
 * @param y вторая переменная
 * @return
 */
double calculate(double x, double y) {
    double result = 0;

    const boolean fitForTheFirstCase = fabs(x) < 5 * fabs(y);
    const boolean fitForTheSecondCase = 5 * fabs(y) < fabs(x) <= 7.5 * fabs(y);

    if (fitForTheFirstCase) {
        printf("\nFirst branch has been chosen\n");

        result = log(fabs(2 * x - 3 * pow(exp(1), 2) * y));
        return result;
    } else if (fitForTheSecondCase) {
        printf("\nSecond branch has been chosen\n");

        result = log(fabs(2 * pow(x, 2) - 3 * y));
        return result;
    } else {
        printf("\nThe entered values (%lf, %lf)"
                       " do not fit for any mentioned in exercise case, so result is equal to 0.0",
               x, y);
        return result;
    }

}

void test() {
    printf("\n\n********TEST*********\n");
    boolean result = testCalculation();
    printf("\nTest passed: %s", result ? "Yes" : "No");
    printf("\n********TEST*********\n\n");
}

/**
 * Тест
 * Сверяет верность рассчетов метода calculate
 *
 * @return верно, или не верно
 */
boolean testCalculation() {
    return testCalculation_firstBranch() && testCalculation_secondBranch();
}

/**
 *   Тестирование первой ветки алгоритма
 *
 * @return успешность прохождения теста
 */
boolean testCalculation_firstBranch() {
    double x = 2;
    double y = -10;

    const double expected = 5.419081;
    double actual = calculate(x, y);

    return assertEquals(actual, expected);
}

/**
 * Тестирование второй ветки алгоритма
 *
 * @return успешность прохождения теста
 */
boolean testCalculation_secondBranch() {
    double x = 7;
    double y = 1;

    const double expected = 4.553877;
    double actual = calculate(x, y);

    return assertEquals(actual, expected);
}

/**
 * Убеждаемся в равенстве ожидаемого и полученного значения
 * С учетом погрешности рассчетов с использованием double
 *
 * @param actual Полученное значение
 * @param expected Ожидаемое значение
 * @return
 */
boolean assertEquals(double actual, double expected) {
    return (expected == actual)
           || (expected - actual <= INACCURACY)
           || (actual - expected <= INACCURACY);
}