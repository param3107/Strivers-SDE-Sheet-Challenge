#include <bits/stdc++.h>
using namespace std;

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    sort(items.begin(), items.end(), [&](pair<int, int> a, pair<int, int> b){return ((double)a.second)/((double)a.first) > ((double)b.second)/((double)b.first);});
    double value;
    for(int i = 0; i < n; i++){
        if(w > 0){
            if(w >= items[i].first){
                value += items[i].second;
                w -= items[i].first;
            }
            else{
                value += ((double)w)*(((double)items[i].second)/((double)items[i].first));
                w = 0;
            }
        }
        else break;
    }
    return ceil(value);
}