#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n){
    int count0 = 0, count1 = 0;
    for(int i = 0; i < n; i++){
        if(!arr[i]) count0++;
        else if(arr[i] == 1) count1++;
    }
    int i = 0;
    while(i < count0){
       arr[i] = 0;
       i++;
    }
    while(i < count0 + count1){
       arr[i] = 1;
       i++;
    }
    while(i < n){
       arr[i] = 2;
       i++;
    }
    return ;
}