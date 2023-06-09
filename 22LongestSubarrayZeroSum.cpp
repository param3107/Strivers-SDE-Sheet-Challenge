#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) { // 1 -1 2 -2
    int sum = 0, maxLength = 0, length = 0;
    unordered_map<int, int> lookup;
    lookup[sum] = -1;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        arr[i] = sum;
        if(!lookup.count(sum)){
            lookup[sum] = i+1;
        }
        else{
            length = i - lookup[sum];
            maxLength = max(length, maxLength);
        }
    }
    return maxLength;
}