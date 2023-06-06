#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    for(int i = 0; i < prices.size()-1; i++){
        prices[i] = prices[i+1] - prices[i];
    }
    int currentSum = 0, maxSum = 0;
    for(int i = 0; i < prices.size() - 1; i++){
        currentSum += prices[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum < 0) currentSum = 0;
    }
    return maxSum;
}
