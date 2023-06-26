#include <bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>> &ans, vector<int> &arr, int i, vector<int> currArr){
    if(i != arr.size()){
        currArr.push_back(arr[i]);
        subset(ans, arr, i+1, currArr);
        while(i < arr.size()-1 && arr[i] == arr[i+1]) i++;
        currArr.pop_back();
        subset(ans, arr, i+1, currArr);
        return;
    }
    ans.push_back(currArr);
    return;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    subset(ans, arr, 0, vector<int> {});
    sort(ans.begin(), ans.end());
    return ans;    
}