#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n){
    vector<vector<long long int>> PT(n);
    PT[0] = vector<long long int> {1};
    for(int i = 0; i < n-1; i++){
        PT[i+1] = vector<long long int> (i+2);
        PT[i+1][0] = 1;
        for(int j = 0; j < i; j++){
            PT[i+1][j+1] = (PT[i][j] + PT[i][j+1]);
        }
        PT[i+1][i+1] = 1;
    }
    return PT;
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){    
        int n;
        cin >> n;
        for(vector<long long int> vec:printPascal(n)){
            for(long long int I:vec){
                cout << I << " ";
            } cout << endl;
        }
    }
    return 0;
}
