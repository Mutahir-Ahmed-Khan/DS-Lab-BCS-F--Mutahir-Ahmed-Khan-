#include <iostream>
using namespace std;
int main(){

    int **department;;
    int d,sum = 0,AvgPos;
    int *employees;
    int *high;
    float *avg;
    float highAvg = -999.9;
    int *ePos;

    cout << "How Many Departments are there? : "; 
    cin >> d;

    department = new int*[d];
    employees = new int[d]; 
    high = new int[d];
    avg = new float[d];
    ePos = new int[d];

    for(int i = 0; i < d; i++){
        cout << "How Many Employees in Department " << i+1 << "?: ";
        cin >> employees[i];

        department[i] = new int[employees[i]]; 
    }

    for(int i = 0; i < d; i++){
        for(int j = 0; j < employees[i]; j++){
            cout << "Enter Employee Salary For Department " << i+1 << " and Employee " << j+1 << ": ";
           cin >> department[i][j];
        }
    }

    for(int i = 0; i < d; i++){
        high[i] = -999;
        avg[i] = 0.0;
        ePos[i] = -1;
    }
    
    for(int i = 0; i < d; i++){
        for(int j = 0; j < employees[i]; j++){
            if(department[i][j] > high[i]){
                high[i] = department[i][j];
                ePos[i] = j;
            }
        }
    }

    cout << endl; 
    cout << "Finding the Highest Salary" << endl;

    for(int i = 0; i < d; i++){
        cout << "Highest Salary in Department " << i + 1 << " is " << high[i] << " of Employee " << ePos[i] + 1;
        cout << endl;
    }

    for(int i = 0; i < d; i++){
        sum = 0;
        for(int j = 0; j < employees[i]; j++){
            sum = sum + department[i][j];
           
        }

        avg[i] = (float)sum / employees[i];
    }

    for(int i = 0; i < d; i++){
        if(avg[i] > highAvg){
            highAvg = avg[i];
            AvgPos = i;
        }
    }


    cout << endl;
    cout << "Overall Maximum Average Salary is: " << highAvg << " in Department " << AvgPos + 1 << endl;

    for(int i = 0; i < d; i++){
        delete[] department[i];
    }
    
    delete[] department;
    delete[] employees;
    delete[] high;
    delete[] avg;
    delete[] ePos;


return 0;
}
