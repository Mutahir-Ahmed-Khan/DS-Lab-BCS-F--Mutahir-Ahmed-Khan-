#include <iostream>
using namespace std;

bool isSafe(char board[9][9], int row, int col, char dig){
    for(int j = 0; j < 9; j++){
        if(board[row][j] == dig){
            return false;
        }
    }

    for(int i = 0; i < 9; i++){
        if(board[i][col] == dig){
            return false;
        }
    }

    int srow = (row/3) * 3;
    int scol = (col/3) * 3;
    for(int i = srow; i <= srow + 2; i++){
        for(int j = scol; j <= scol + 2; j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }

    return true;
}

bool helper(char board[9][9], int row, int col){

    if(row == 9){
        return true;
    }

    int nextRow = row , nextCol = col + 1;
    if(nextCol == 9){
        nextRow = row + 1;
        nextCol = 0; 
    }

    if(board[row][col] != '.'){
        return helper(board, nextRow, nextCol);
    }

    for(char digit = '1'; digit <= '9'; digit++){
        if(isSafe(board, row, col, digit)){
            board[row][col] = digit;
            if(helper(board, nextRow, nextCol)){
                return true;
            }
            else{
                board[row][col] = '.';
            }
        }
    }

    return false;
}

int main(){
    
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (helper(board, 0, 0)) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!\n";
    }

return 0;
}
