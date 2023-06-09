#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n){
    int count = 1, countMax = 1;
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == arr[i-1]+1){
            count++;
            countMax = max(countMax, count);
        }
        else if(arr[i] == arr[i-1]) continue;
        else{
            count = 1;
        }
    }
    return countMax;
}