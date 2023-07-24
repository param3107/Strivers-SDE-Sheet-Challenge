#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> sorter;
    for(int i = 0; i < start.size(); i++){
        sorter.push_back({finish[i], start[i]});
    }
    int endTime = 0, acts = 0;
    sort(sorter.begin(), sorter.end());
    for(int i = 0; i < start.size(); i++){
        if(sorter[i].second >= endTime){
            endTime = sorter[i].first;
            acts++;
        }
    }
    return acts;
}