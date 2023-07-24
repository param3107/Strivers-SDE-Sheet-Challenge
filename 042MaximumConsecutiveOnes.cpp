#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    if(k >= n) return n;
    else if(n == 1){
        if(k) return 1;
        else return arr[0];
    }
    int start = 0, count = 1, zeroes = 0, maxLength = 0;
    for(int i = 0; i < n; i++){
        count = 1;
        while(i < n-1){
            if(arr[i] == arr[i+1]){
                count++;
                i++;
            }
            else break;
        }
        if(arr[i]){
            arr[start] = count;
            maxLength = max(maxLength, count);
        }
        else{
            arr[start] = -count;
            zeroes += count;
        }
        start++;
    }
    if(k == 0) return maxLength;
    if(k >= zeroes) return n;
    if(zeroes == n) return k;
    if(zeroes == 0) return n;
    count = 0;
    int remain = k;
    int high = 0, low = 0;
    maxLength = 0;
    while(high != start){ // 1 -2 2 -1 1
        if(arr[high] > 0){
            count += arr[high];
            high++;
        }
        else if(arr[high] < 0){
            if(remain >= -arr[high]){
                remain += arr[high];
                count += -arr[high];
                high++;
            }
            else{
                count += remain;
                maxLength = max(maxLength, count);
                count -= remain;
                if(arr[low] >= 0){
                    count -= arr[low];
                    low++;
                }
                else{
                    if(high == low){
                        arr[low] = -remain;
                        count += remain;
                        remain = 0;
                        high++;
                    }
                    else if(-arr[low] >= -arr[high] - remain){
                        if(count) count -= -arr[high] - remain;
                        arr[low] += -arr[high] - remain; 
                        remain = -arr[high];
                    }
                    else{
                        count -= -arr[low];
                        remain += -arr[low];
                        low++;
                    }
                }
            }
        }
        maxLength = max(maxLength, count);
    }
    return maxLength;
}
