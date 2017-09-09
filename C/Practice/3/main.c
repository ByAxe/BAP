#include <stdio.h>
#include <jmorecfg.h>
#include <math.h>

#define INACCURACY 0.001

struct Triple {
    double Yx;
    double Sx;
    double diff;
};

void test();

boolean testCalculation();

boolean assertEqualsDoubles(double actual, double expected);

boolean assertEqualsStructs(struct Triple actual, struct Triple expected);

struct Triple calculate(double x, int n);

double calculateYx(double x);

double calculateSx(double x, int n);

double calculateDiff(double Yx, double Sx);

/**
 * Точка входа в программу.
 * 1) Ввод данных пользователем
 * 2) Тест в конце, для удостоверения что все работает хорошо
 *
 * @return
 */
int main() {

    // 1)
    const int n = 2;
    double x;

    puts("\n\t x = ");
    scanf("%lf", &x);

    struct Triple result = calculate(x, n);
    printf("Result: \n\tS(x): \t\t\t%lf", result.Sx);
    printf("\n\tY(x): \t\t\t%lf", result.Yx);
    printf("\n\t|S(x)-Y(x)|: \t%lf", result.diff);

    // 2)
    test();

    return 0;
}

void test() {
    printf("\n\n********TEST*********");
    boolean result = testCalculation();
    printf("\nTest passed: %s", result ? "Yes" : "No");
    printf("\n********TEST*********\n\n");
}

/**
 * Основные рассчеты по задаче
 *
 * @param x первая переменная
 * @param n количество итераций цикла для суммы
 * @return экземпляр структуры, в котором хранятся все наши результаты
 */
struct Triple calculate(double x, int n) {
    struct Triple result;

    result.Yx = calculateYx(x);
    result.Sx = calculateSx(x, n);
    result.diff = calculateDiff(result.Yx, result.Sx);

    return result;
}

double calculateYx(double x) {
    return x * atan(x) - log(sqrt(1 + x * x));
}

double calculateSx(double x, int n) {
    double result = 0;

    for (int k = 1; k <= n; ++k) {
        result += pow((-1), k + 1) * ((pow(x, 2 * k)) / ((2 * k) * (2 * k - 1)));
    }

    return result;
}

double calculateDiff(double Yx, double Sx) {
    return fabs(Yx - Sx);
}

/**
 * Тест
 * Сверяет верность рассчетов метода calculate
 *
 * @return верно, или не верно
 */
boolean testCalculation() {
    struct Triple expected;
    expected.Yx = 0.0049916998225322399;
    expected.Sx = 0.0049916666666666677;
    expected.diff = 0.000000033155865572162546;

    double x = 0.1;
    int n = 2;

    struct Triple actual = calculate(x, n);

    return assertEqualsStructs(actual, expected);
}

/**
 * Убеждаемся в равенстве ожидаемого и полученного значения
 * Для двух структур
 *
 * @param actual полученное значение
 * @param expected ожидаемое значение
 * @return равны значения или нет
 */
boolean assertEqualsStructs(struct Triple actual, struct Triple expected) {
    return assertEqualsDoubles(actual.Yx, expected.Yx)
           && assertEqualsDoubles(actual.Sx, expected.Sx)
           && assertEqualsDoubles(actual.diff, expected.diff);
}

/**
 * Убеждаемся в равенстве ожидаемого и полученного значения
 * С учетом погрешности рассчетов с использованием double
 *
 * @param actual Полученное значение
 * @param expected Ожидаемое значение
 * @return равны значения, или нет
 */
boolean assertEqualsDoubles(double actual, double expected) {
    return (expected == actual)
           || (expected - actual <= INACCURACY && expected - actual > 0)
           || (actual - expected <= INACCURACY && actual - expected > 0);
}