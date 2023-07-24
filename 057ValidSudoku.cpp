#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int num, int matrix[9][9]){
    for(int i = 0 ; i < 9; i++){
        if(matrix[x][i] == num) return false;
        if(matrix[i][y] == num) return false;
    }
    for(int i = (x/3)*3; i <= (x/3)*3+2; i++){
        for(int j = (y/3)*3; j <= (y/3)*3+2; j++){
            if(matrix[i][j] == num) return false;
        }
    }
    return true;
}

bool nextMove(int x, int y, int matrix[9][9]){
    bool ans = false;
    if(matrix[x][y]){
        if(x == 8 && y == 8) ans = true;
        else if(x%3 == 2 && y%3 != 2) ans = nextMove(x-2, y+1, matrix);
        else if(x == 8 && y%3 == 2) ans = nextMove(0, y+1, matrix);
        else if(x%3 == 2 && y%3 == 2) ans = nextMove(x+1, y-2, matrix);
        else ans = nextMove(x+1, y, matrix);
        return ans;
    }
    else{
        for(int i = 1; i <= 9; i++){
            if(isSafe(x, y, i, matrix)){
                matrix[x][y] = i;
                if(x == 8 && y == 8) ans = true;
                else if(x%3 == 2 && y%3 != 2) ans = nextMove(x-2, y+1, matrix);
                else if(x == 8 && y%3 == 2) ans = nextMove(0, y+1, matrix);
                else if(x%3 == 2 && y%3 == 2) ans = nextMove(x+1, y-2, matrix);
                else ans = nextMove(x+1, y, matrix);
                if(ans) return true;
            }
        }
        matrix[x][y] = 0;
        return false;
    }
}

bool isItSudoku(int matrix[9][9]) {
    return nextMove(0, 0, matrix);
}
