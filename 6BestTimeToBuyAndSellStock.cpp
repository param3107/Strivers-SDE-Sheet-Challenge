#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int currentSum = 0, maxSum = 0;
    for(int i = 0; i < prices.size()-1; i++){
        prices[i] = prices[i+1] - prices[i];
        currentSum += prices[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum < 0) currentSum = 0;
    }
    return maxSum;
}
