#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){   
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int size = intervals.size();
    int ansIndex = 0;
    ans.push_back(intervals[0]);
    for(int i = 1; i < size ; i++){
        if(ans[ansIndex][1] >= intervals[i][0]){
            ans[ansIndex][1] = max(intervals[i][1], ans[ansIndex][1]);
        }
        else{
            ans.push_back(intervals[i]);
            ansIndex++;
        }
    }   
    return ans;
}