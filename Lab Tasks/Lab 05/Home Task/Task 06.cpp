#include <iostream>
#include <string>
using namespace std;

#define n 4

void helper(int mat[n][n], int r, int c, string path, bool vis[n][n]){

    if(r < 0 || c < 0 || r >= n || c>= n || vis[r][c] || mat[r][c] == 0){
        return;
    }

    if( r == n - 1 && c == n - 1){
        cout << path << endl;
        return;
    }

    vis[r][c] = true;

    helper(mat, r - 1, c, path + "U",vis);
    helper(mat, r + 1, c, path + "D",vis);
    helper(mat, r, c - 1, path + "L",vis);
    helper(mat, r, c + 1, path + "R",vis);

    vis[r][c] = false;
}

void findPath(int mat[n][n]){
    bool vis[n][n] = {false};

    if(mat[0][0] == 0){
        cout << "No Path Exist" << endl;
        return;
    }

    cout << "All Possible Paths: " << endl;
    helper(mat, 0 , 0, "", vis);
}

int main(){

    int maze[n][n] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    findPath(maze);

return 0;
}
