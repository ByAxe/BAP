#include <cstdio>

int calculate(int row, int column, int **array);

/**
 * Точка входа в программу.
 *
 * @return
 */
int main() {
    int **a, i, j, n, m, result;
    puts("\n\tInput N, M : ");
    scanf("%i %i", &n, &m);
    a = new int *[n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("\t a[%i][%i] = ", i + 1, j + 1);
            scanf("%i", &a[i][j]);
        }
    }

    result = calculate(n, m, a);
    printf("Result: %i", result);
    delete[]a;


    return 0;
}

/**
 * Расчет произведения элементов, расположенных на главной диагонали матрицы
 *
 * @param row количество строк матрицы
 * @param column количество столбцов матрицы
 * @param array матрица
 * @return произведение элементов главной диагонали
 */
int calculate(int row, int column, int **array) {
    int i, j, result = 1;

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (i == j) {
                result *= array[i][j];
            }
        }
    }
    return result;
}