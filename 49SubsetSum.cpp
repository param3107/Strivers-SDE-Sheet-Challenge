#include <bits/stdc++.h>
using namespace std;

void sum(vector<int> &ans, vector<int> &num, int i, int currSum){
    if(i!=num.size()){
        sum(ans, num, i+1, currSum);
        sum(ans, num, i+1, currSum + num[i]);
        return;
    }
    ans.push_back(currSum);
    return;
}

vector<int> subsetSum(vector<int> &num){
    vector<int> ans;
    sum(ans, num, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}