#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr){
    if(arr.size() == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[arr.size()-1] != arr[arr.size()-2]) return arr[arr.size()-1];
	int low = 0, high = arr.size()-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(mid%2 == 0){
            if(arr[mid] == arr[mid+1]) low = mid+1;
            else if(arr[mid] == arr[mid-1]) high = mid-1;
            else return arr[mid];
        }
        else{
            if(arr[mid] == arr[mid+1]) high = mid-1;
            else if(arr[mid] == arr[mid-1]) low = mid+1;
            else return arr[mid];
        }
    }
}