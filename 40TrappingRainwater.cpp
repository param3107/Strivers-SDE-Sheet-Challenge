#include <bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr ,int n){
    long low = 0, high = n-1;
    long water = 0;
    long preMax = 0, postMax = 0;
    while(low < high){
        if(arr[low] <= arr[high]){
            if(preMax < arr[low]) preMax = arr[low];
            else water += preMax - arr[low];
            low++; 
        }
        else{
            if(postMax < arr[high]) postMax = arr[high];
            else water += postMax - arr[high];
            high--;
        }
    }
    return water;
}