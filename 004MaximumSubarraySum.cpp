#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long int maxSum = 0, currentSum = 0;
    for(int i = 0; i < n; i++){
        currentSum += arr[i];
        if(currentSum < 0) currentSum = 0;
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}