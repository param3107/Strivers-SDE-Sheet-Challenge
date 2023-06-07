#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n){
    int index[n] = {0};
    int miss, repeat;
    for(int i = 0; i < n; i++){
        index[arr[i] - 1]++;
    }
    for(int i = 0; i < n; i++){
        if(index[i] == 0) miss = i+1;
        else if(index[i] == 2) repeat = i+1; 
    }
    return make_pair(miss, repeat);
}