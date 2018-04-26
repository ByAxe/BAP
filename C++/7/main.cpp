using namespace std;

#include <iostream>


int main() {

    struct Material {
        char title[30];
        int amount;
        double price;
        char date[30];
    } materials[100];

    int amount, threshold = 100000;
    cout << "Enter amount of materials: ";
    cin >> amount;

    for (int i = 0; i < amount; i++) {
        cout << "Enter title of material: ";
        cin >> materials[i].title;

        cout << "Enter amount of current material: ";
        cin >> materials[i].amount;

        cout << "Enter a price of material: ";
        cin >> materials[i].price;

        cout << "Enter a date of incoming: ";
        cin >> materials[i].date;
    }

    cout << "Materials with price > " << threshold << ":" << endl;

    for (int j = 0; j < amount; ++j) {
        auto m = materials[j];
        if (m.price > threshold) {
            cout << "Material " << j
                 << " -> title: " << m.title
                 << ", amount: " << m.amount
                 << ", price: " << m.price
                 << ", date: " << m.date
                 << endl;
        }
    }

    return 0;
}