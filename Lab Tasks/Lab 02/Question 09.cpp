    #include <iostream>
    using namespace std;
    int main(){

        int rows, k = 0;
        int nonZero = 0;
        int coloumns;
        int** matrix;
        int *rowPos;
        int *coloumnPos;
        int *Value;

        cout << "Enter Number Of Rows: "; 
        cin >> rows;

        cout << "Enter Number Of Coloumns: ";
        cin >> coloumns;

        matrix = new int*[rows];
        for(int i = 0; i < rows; i++){
            matrix[i] = new int[coloumns];
        }


        for(int i = 0; i < rows; i++){
            for(int j = 0; j < coloumns; j++ ){
                cout << "Enter the Number for Matrix  " << "(" << i << "," << j << "):";
                cin >> matrix[i][j];
                if(matrix[i][j] != 0){
                    nonZero++;
                }
            }
        }

        cout << endl;
        cout << "A Normal Matrix"<< endl;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < coloumns; j++){
                cout << matrix[i][j];
                cout << " ";
            }
            cout << endl;
        }

        rowPos = new int[nonZero];
        coloumnPos = new int[nonZero];
        Value = new int[nonZero];

        for(int i = 0; i < nonZero; i++){
            rowPos[i] = 0;
            coloumnPos[i] = 0;
            Value[i] = 0;
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < coloumns; j++){
                if(matrix[i][j] != 0){
                    rowPos[k] = i;
                    coloumnPos[k] = j;
                    Value[k] = matrix[i][j];
                    k++;
                }
            }
        }
        cout << endl;

        cout << "Sparse Matrix" << endl;
        for (int i = 0; i < nonZero; i++) {
            cout << rowPos[i] << " " << coloumnPos[i] << " " << Value[i] << endl;
        }

        for(int i = 0; i < rows; i++){
            delete[] matrix[i];
        }

        delete[] matrix;
        delete[] rowPos;
        delete[] coloumnPos;
        delete[] Value;

    return 0;
    }
