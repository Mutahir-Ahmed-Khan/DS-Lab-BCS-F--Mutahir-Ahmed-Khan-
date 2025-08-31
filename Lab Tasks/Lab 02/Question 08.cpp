
#include <iostream>
using namespace std;

int main() {
    int n, m;   
    double **temperature;  
    double *daily; 
    double sum = 0;
    int HD = 0, CD = 0;

    cout << "Enter number of days: ";
    cin >> n;

    cout << "Enter number of readings per day: ";
    cin >> m;

    
    temperature = new double*[n];
    daily = new double[n];

    for (int i = 0; i < n; i++) {
        temperature[i] = new double[m];
    }

    
    for (int i = 0; i < n; i++) {
        cout << "Enter temperatures for Day " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "Reading " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < m; j++) {
            sum = sum + temperature[i][j];
        }
        daily[i] = sum / m;
    }

    for (int i = 1; i < n; i++) {
        if (daily[i] > daily[HD]) {
            HD = i;
        }
        if (daily[i] < daily[CD]) {
            CD = i;
        }
    }

    cout << "Daily Average Temperatures:";
    for (int i = 0; i < n; i++) {
        cout << "Day " << i + 1 << ": " << daily[i] << endl;
    }

    cout << "Hottest Day: Day " << HD + 1 << endl;
    cout << "Coldest Day: Day " << CD + 1 << endl;

    for (int i = 0; i < n; i++) {
        delete[] temperature[i];
    }
    delete[] temperature;
    delete[] daily;

    return 0;
}
