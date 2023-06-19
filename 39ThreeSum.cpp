#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K){
    vector<vector<int>> ans;
    if(n < 3) return ans;
    sort(arr.begin(), arr.end());
    int low, mid, high;
    for(int i = 0; i < n-2; i++){
        low = i;
        mid = i+1;
        high = n-1;
        while(mid < high){
            if(arr[low] + arr[mid] + arr[high] > K) high --;
            else if(arr[low] + arr[mid] + arr[high] < K) mid ++;
            else{
                if(arr[mid] == arr[high]){
                    ans.push_back({arr[low], arr[mid], arr[high]});
                    break;
                }
                else{
                    while(arr[mid] == arr[mid+1]){
                        mid++;
                    }
                    while(arr[high] == arr[high-1]){
                        high--;
                    }
                    ans.push_back({arr[low], arr[mid], arr[high]});
                    mid++;
                    high--;
                }
            }
        }
        while(arr[i] == arr[i+1]) i++;
    }
    return ans;
}