#include <iostream>
using namespace std;
int main(){

    //Assuming the matrix 01 and matrix 02 both have same rows and coloumns

    int rows;
    int coloumns;
    int** matrix;
    int** matrix2;  
    int **addition;
    int ** subtraction;

    cout << "Enter Number Of Rows: "; 
    cin >> rows;

    cout << "Enter Number Of Coloumns: ";
    cin >> coloumns;

    matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[coloumns];
    }

    matrix2 = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix2[i] = new int[coloumns];
    }

    addition = new int*[rows];
    for(int i = 0; i < rows; i++){
        addition[i] = new int[coloumns];
    }

    subtraction = new int*[rows];
    for(int i = 0; i < rows; i++){
        subtraction[i] = new int[coloumns];
    }
    
    //-----------------------

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < coloumns; j++ ){
            cout << "Enter the Number for Matrix 01 " << "(" << i << "," << j << "):";
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < coloumns; j++ ){
            cout << "Enter the Number for Matrix 02 " << "(" << i << "," << j << "):";
            cin >> matrix2[i][j];
        }
    }

    //---------
    for(int i = 0; i <rows; i++){
        for(int j = 0; j < coloumns; j++){
            addition[i][j] = matrix[i][j] + matrix2[i][j]; 
        }
    }

    cout << "ADDITION OF THE MATRICES" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < coloumns; j++){
            cout << addition[i][j];
            cout << " ";
        }
        cout << endl;
    }
    //-----------
    for(int i = 0; i <rows; i++){
        for(int j = 0; j < coloumns; j++){
            subtraction[i][j] = matrix[i][j] - matrix2[i][j]; 
        }
    }

    cout << "SUBTRACTION OF THE MATRICES" << endl; 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < coloumns; j++){
            cout << subtraction[i][j];
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
        delete[] matrix2[i];
        delete[] subtraction[i];
        delete[] addition[i];
    }

    delete[] matrix;
    delete[] matrix2;
    delete[] subtraction;
    delete[] addition;

return 0;
}
