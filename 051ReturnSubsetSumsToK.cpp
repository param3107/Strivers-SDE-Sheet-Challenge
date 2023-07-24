#include <bits/stdc++.h>
using namespace std;

void subsetSumK(vector<vector<int>> &ans, vector<int> &arr, int i, vector<int> currArr, int k){
    if(i != arr.size()){
        if(currArr[0] == k){
            ans.push_back({currArr.begin()+1, currArr.end()});
            return;
        }
        subsetSumK(ans, arr, i+1, currArr, k);
        currArr.push_back(arr[i]);
        currArr[0] += arr[i];
        subsetSumK(ans, arr, i+1, currArr, k);
        return;
    }
    if(currArr[0] == k){
            ans.push_back({currArr.begin()+1, currArr.end()});
            return;
    }
    return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    vector<vector<int>> ans;
    subsetSumK(ans, arr, 0, {0}, k);
    return ans;
}