#include <bits/stdc++.h> 
using namespace std;

int merge(vector<int> &arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int count = 0;

    int j = 0;
    for(int i = 0; i < n1; i++){
        while(j < n2 && arr[i+l] > (2*arr[mid+1+j])) j++;
        count += j;
    }
    
    int a[n1], b[n2];
    for(int i = 0; i < n1; i++) a[i] = arr[l+i];
    for(int i = 0; i < n2; i++) b[i] = arr[mid+1+i];
    
    int i = 0;
    j = 0;
    for(int k = 0; k < r-l+1; k++){
        if(i < n1 && j < n2){
            if(a[i] < b[j]){
                arr[k+l] = a[i];
                i++;
            }
            else{
                arr[k+l] = b[j];
                j++;
            }
        }
        else if(i < n1){
            arr[k+l] = a[i];
            i++;
        }
        else if(j < n2){
            arr[k+l] = b[j];
            j++;
        }
    }
    return count;
}

int mergeSort(vector<int> &arr, int l, int r){
    int count = 0;
    if(l < r){
        int mid = (l+r)/2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, r);
        count += merge(arr, l, mid, r);
    }
    return count;
}

int reversePairs(vector<int> &arr, int n){
    return mergeSort(arr, 0, n-1);
}