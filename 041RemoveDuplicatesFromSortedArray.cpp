#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n){
    if(n == 1) return 1; 
    int start = 0;
    for(int i = 0; i < n; i++){
        while(i < n-1){
            if(arr[i] == arr[i+1]) i++;
            else break;
        }
        arr[start] = arr[i];
        start++;
    }
    return start;
}