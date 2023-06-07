#include <bits/stdc++.h> 

int merge(long long arr[], int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int count = 0;
    int a[n1], b[n2];
    for(int i = 0; i <  n1; i++) a[i] = arr[l+i]; 
    for(int i = 0; i < n2; i++) b[i] = arr[mid+i+1];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k++] = a[i++];
        }
        else {
            arr[k++] = b[j++];
            count += mid-l-i+1;
        }
    }
    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
    return count;
}

int mergeSort(long long arr[], int l, int r){
    int count = 0;
    if(l < r){
        int mid = (l+r)/2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, r); 
        count += merge(arr, l, mid, r);
    }
    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}