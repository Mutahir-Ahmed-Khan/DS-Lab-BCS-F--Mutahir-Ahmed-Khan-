#include <iostream>
using namespace std;

//This Function is to check the Conditions of the sudoku Problem
//Digit placed Should not be present 
//Vertically 
//horizontally
// In corresponding 3x3 Grid
bool isSafe(char board[9][9], int row, int col, char dig){
  //Checking Horizontally
    for(int j = 0; j < 9; j++){
        if(board[row][j] == dig){
            return false;
        }
    }
//Checking vertically
    for(int i = 0; i < 9; i++){
        if(board[i][col] == dig){
            return false;
        }
    }

//checking in 3x3 Grid
  //Approach ranges form 0 to 2, 3 to 5, 6 to 8 have respectively coloumns with them 
  //Calculated below
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

  //Base Case: means that whole grid is solved
    if(row == 9){
        return true;
    }

  //To traverse in the grid
    int nextRow = row , nextCol = col + 1;
    if(nextCol == 9){
        nextRow = row + 1;
        nextCol = 0; 
    }

  //if digit is aleready printed -> traverse
    if(board[row][col] != '.'){
        return helper(board, nextRow, nextCol);
    }

  //If digit is not already in the grid -> add digit
    for(char digit = '1'; digit <= '9'; digit++){
        if(isSafe(board, row, col, digit)){
            board[row][col] = digit;
          //if grid is not solved then
            if(helper(board, nextRow, nextCol)){
                return true;
            }
            //backTrack and come to the preious didgit enetered and change it to '.'
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
