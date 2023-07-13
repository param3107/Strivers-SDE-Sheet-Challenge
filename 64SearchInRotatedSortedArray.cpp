#include <bits/stdc++.h>
using namespace std;
int search(int* arr, int n, int key){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid] >= arr[low]){
            if(key < arr[mid] && key >= arr[low]) high = mid-1;
            else low = mid+1;
        }
        else{
            if(key > arr[mid] && key <= arr[high]) low = mid+1;
            else high = mid-1;
        }       
    }
    return -1;
}