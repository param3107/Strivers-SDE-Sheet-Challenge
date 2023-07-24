#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n){
    int *low = arr, *mid = arr, *high = arr + n-1;
    while(mid <= high){
        if(*mid == 0){
            swap(*low, *mid);
            low++; mid++;
        }
        else if(*mid == 1) mid++;
        else{
            swap(*mid, *high);
            high --;
        }
    }
}