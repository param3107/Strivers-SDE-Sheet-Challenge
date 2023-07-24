#include <bits/stdc++.h> 
using namespace std;

int uniquePaths(int m, int n){
    long long num = 1, denom = 1;
    for(int i = 2; i < m; i++){
        denom *= i;
    }
    for(int i = n; i < (m + n - 1); i++){
        num *= i;
    }
    return num/denom;
}