using namespace std;

#include <iostream>
#include <iomanip>

int main() {
    /*
     * 1. Variables
     * */
    double **a, tmp;
    int i, j, n, m = 0, amount = 0;

    /*
     * 2. Entering everything
     * */
    cout << "Enter size: n, m" << endl;
    cin >> n >> m;
    a = new double *[n];
    for (i = 0; i < n; i++) {
        a[i] = new double[m];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << "Enter a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    /*
     * 3. Show entered array
     * */
    cout << "Array A:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << setw(9) << a[i][j] << " ";
        }
        cout << endl;
    }

    /*
     * 4. Main logic
     * */
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (j > i and a[i][j] < 0) {
                amount++;
            }
        }
    }

    /*
     * 5. Show results
     * */
    cout << "Number of negative elements = " << amount << endl;

    /*
     * 6. Free up a memory
     * */
    for (i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[]a;
    a = nullptr;
    return 0;
}
