#include <bits/stdc++.h>
using namespace std;

void insertConfig(vector<vector<int>> &ans, int (&queens)[10], int n){
    vector<int> config;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(queens[i] == j) config.push_back(1);
            else config.push_back(0);
        }
    }
    ans.push_back(config);
    return;
}

bool isSafe(pair<int, int> square, int (&queens)[10]){
    for(int i = 0; i < square.first; i++){
        if(square.second == queens[i] || 
        abs(square.first - i) == abs(square.second - queens[i])) return false;
    }
    return true;
}

void moveNext(int row, int (&queens)[10], int n, vector<vector<int>> &ans){
    for(int i = 0; i < n; i++){
        if(isSafe({row, i}, queens)){
            queens[row] = i;
            if(row == n-1) insertConfig(ans, queens, n);
            else moveNext(row+1, queens, n, ans);
        }
    }
    return;
}

vector<vector<int>> solveNQueens(int n){
    vector<vector<int>> ans;
    int queens[10];
    for(int i = 0; i < 10; i++){
        queens[i] = -1;
    }  
    moveNext(0, queens, n, ans);
    return ans;
}