#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
	int rows[n]  = {0};
	int columns[m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(rows[i]){
            for(int j = 0; j < m; j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 0; j < m; j++){
        if(columns[j]){
            for(int i = 0; i < n; i++){
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
            }
        }
        setZeros(matrix);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << matrix[i][j] << " ";
            } cout << endl;
        }
    }
    return 0;
}