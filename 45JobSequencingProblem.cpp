#include <bits/stdc++.h> 
using namespace std;

int jobScheduling(vector<vector<int>> &jobs){
    int profit = 0;
    int lastDeadline = INT_MIN;
    sort(jobs.begin(), jobs.end(), [&](vector<int> a, vector<int> b){return a[1] > b[1];});
    for(int i = 0; i < jobs.size(); i++){
        lastDeadline = max(lastDeadline, jobs[i][0]);
    }
    int schedule[lastDeadline] = {0};
    for(int i = 0; i < jobs.size(); i++){
        if(schedule[jobs[i][0]-1] == 0){
            schedule[jobs[i][0]-1] = jobs[i][1];
            profit += jobs[i][1];
        }
        else{
            int j = jobs[i][0]-1;
            while(schedule[j]){
                if(j>0) j--;
                else if(j == 0) break;
            }
            if(!schedule[j]){
                schedule[j] = jobs[i][1];
                profit += jobs[i][1];
            }
        }
    }
    return profit;
}
