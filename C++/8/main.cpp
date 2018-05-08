using namespace std;

#include <iostream>
#include <cmath>
#include <iomanip>

typedef double (*uf)(double, int);

void Table(double, double, double, uf);

double Y(double, int);

int main() {
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << endl;
    Table(0.1, 1, 0.1, Y);
    cout << endl;
    return 0;
}

void Table(double a, double b, double h, uf fun) {
    int k = 0;
    double sum;
    for (double x = a; x < b + h / 2; x += h) {
        sum = fun(x, 20);
        cout << setw(8) << x << setw(15) << sum << endl;
    }
}

double Y(double x, int k) {
    double s = 2;
    for (int i = 1; i <= k; i++)
        s += 2 * pow(x, i) / pow(cos(x), i);
    return s;
}
