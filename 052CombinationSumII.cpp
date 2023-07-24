#include <bits/stdc++.h>
using namespace std;

void subsetSumK(vector<vector<int>> &ans, vector<int> &arr, int i, vector<int> currArr, int k){
    if(i != arr.size()){
        if(currArr[0] == k){
            ans.push_back({currArr.begin()+1, currArr.end()});
            return;
        }
        else if(currArr[0] < k){
            currArr.push_back(arr[i]);
            currArr[0] += arr[i];
            subsetSumK(ans, arr, i+1, currArr, k);
            currArr[0] -= arr[i];
            currArr.pop_back();
            while(i < arr.size()-1 && arr[i] == arr[i+1]) i++;
            subsetSumK(ans, arr, i+1, currArr, k);
            return;
        }
        else return;
    }
    if(currArr[0] == k) ans.push_back({currArr.begin()+1, currArr.end()});
    return;     
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    subsetSumK(ans, arr, 0, {0}, target);
    sort(ans.begin(), ans.end());
    return ans;
}
