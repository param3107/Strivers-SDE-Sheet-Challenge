#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    bool found = false;
    sort(arr.begin(), arr.end()); 
    int i = 0, j = 1, k = n-2, l = n-1;
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(i > i+1 && arr[j] == arr[j-1]) continue;

            int k = j+1, l = n-1;
            while(k < l){
                if(arr[i] + arr[j] + arr[k] + arr[l] < target) k++;
                else if(arr[i] + arr[j] + arr[k] + arr[l] > target) l--;
                else{
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(found) break;
    }
    if(found) return "Yes";
    return "No";
}
