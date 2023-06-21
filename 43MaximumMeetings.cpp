#include <bits/stdc++.h>
using namespace std;

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int, pair<int, int>>> sorter;
    for(int i = 0; i < start.size(); i++){
        sorter.push_back({end[i], {i+1, start[i]}});
    }
    sort(sorter.begin(), sorter.end());
    vector<int> ans;
    ans.push_back(sorter[0].second.first);
    int endTime = sorter[0].first;
    for(int i = 1; i < sorter.size(); i++){
        if(sorter[i].second.second > endTime){
            ans.push_back(sorter[i].second.first);
            endTime = sorter[i].first;
        }
    }
    return ans; 
}