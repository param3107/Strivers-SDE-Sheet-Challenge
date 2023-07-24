#include <bits/stdc++.h>
using namespace std;

int lessThanMid(int mid, vector<int> &arr){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int m = (low + high)/2;
        if(arr[m] <= mid) low = m+1;
        else high = m-1;
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix){
    // int Max = INT_MIN, Min = INT_MAX;
    // for(int i = 0; i < matrix.size(); i++){
    //     Max = max(Max, matrix[i][matrix.size()-1]);
    //     Min = min(Min, matrix[i][0]);
    // }
    int low = 1, high = 1e5;
    while(low <= high){
        int count = 0;
        int mid = (low + high)/2;
        for(int i = 0; i < matrix.size(); i++){
            count += lessThanMid(mid, matrix[i]);
        }
        if(count <= ((matrix.size()*matrix[0].size())/2)) low = mid+1;
        else high = mid-1;
    }
    return low;
}
