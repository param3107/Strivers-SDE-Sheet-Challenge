#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> temp = {arr1.begin(), arr1.begin() + m};
    int i = 0, j = 0;
    for(int k = 0; k < m+n; k++){
        if(i < m && j < n){
            if(temp[i] < arr2[j]){
                arr1[k] = temp[i];
                i++;
            }
            else{
                arr1[k] = arr2[j];
                j++;
            }
        }
        else if(i >= m){
            arr1[k] = arr2[j];
            j++;
        }
        else if(j >= n){
            arr1[k] = temp[i];
            i++;
        }
    }
    return arr1;
}