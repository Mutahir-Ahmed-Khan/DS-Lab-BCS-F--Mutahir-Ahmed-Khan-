#include <iostream>
using namespace std;

float* resizeArray(float *oldArr, int oldSize, int newSize) {
    if (oldSize == newSize) {
        return oldArr;
    }

    float* newArr = new float[newSize];

    int limit = (oldSize < newSize) ? oldSize : newSize;

    for (int i = 0; i < limit; i++) {
        newArr[i] = oldArr[i];
    }

    delete[] oldArr;
    return newArr;
}

int main() {
    int n;
    float *expenses;
    char m;
    int a;

    cout << "Enter the Months: ";
    cin >> n;

    expenses = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Expense for Month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    do {
        float avg = 0.0;

        cout << "\nExpenses:\n";
        for (int i = 0; i < n; i++) {
            cout << "Month " << i + 1 << ": " << expenses[i] << endl;
            avg += expenses[i];
        }

        cout << "Average: " << avg / n << endl;

        cout << "\nDo you want to add more months? (y/n): ";
        cin >> m;

        if (m == 'y') {
            cout << "How many extra months?: ";
            cin >> a;

            expenses = resizeArray(expenses, n, n + a);

            for (int i = n; i < n + a; i++) {
                cout << "Enter Expense for Month " << i + 1 << ": ";
                cin >> expenses[i];
            }

            n += a; 
        }

    } while (m == 'y');

    delete[] expenses;
    return 0;
}
