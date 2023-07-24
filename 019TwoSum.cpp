#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    int asc = 0, desc = 0;
    int low, high;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] >= arr[i-1]){
            asc++;
        }
        else desc++;
    }
    if(asc >= desc){
        sort(arr.begin(), arr.end()); // -6 2 2 2 5
        low = 0;
        high = arr.size() - 1;
        while(low < high){
            if(arr[low] + arr[high] > s) high--;
            else if(arr[low] + arr[high] < s) low++;
            else{
                ans.push_back({arr[low], arr[high]});
                if((arr[high] == arr[high-1] || arr[low] == arr[low+1])){
                    int count1 = 1, count2 = 1;
                    if(arr[low] == arr[high]){
                        count1 = (high - low + 1)/2;
                        count2 = (high - low + 1) - count1;
                        low += count1;
                        high -= count2;
                        count1 = (count1 + count2)*(count1 + count2 -1)/2;
                        count2 = 1;
                    }
                    else{
                        while(low < high){
                            if(arr[low] == arr[low+1]){
                                count1++;
                                low++;
                            }
                            else if(arr[high] == arr[high-1]){
                                count2++;
                                high--;
                            }
                            else break;
                        }
                    }
                    for(int i = 0; i < (count1*count2 - 1); i++){
                        ans.push_back({arr[low], arr[high]});
                    }
                    low++;
                    high--;
                }
                else low++;
            }
        }
    }
    else{
        sort(arr.begin(), arr.end(), greater<int>());
        high = 0;
        low = arr.size() - 1;
        while(high < low){
            if(arr[low] + arr[high] > s) high++;
            else if(arr[low] + arr[high] < s) low--;
            else{
                ans.push_back({arr[low], arr[high]});
                if((arr[high] == arr[high+1] || arr[low] == arr[low-1])){
                    int count1 = 1, count2 = 1;
                    if(arr[low] == arr[high]){
                        count1 = (low - high + 1)/2;
                        count2 = (low - high + 1)- count1;
                        high += count1;
                        low -= count2;
                        count1 = (count1 + count2)*(count1 + count2 -1)/2;
                        count2 = 1;
                    }
                    else{
                        while(high < low){
                            if(arr[low] == arr[low-1]){
                                count1++;
                                low--;
                            }
                            else if(arr[high] == arr[high+1]){
                                count2++;
                                high++;
                            }
                            else break;
                        }
                    }
                    for(int i = 0; i < (count1*count2 - 1); i++){
                        ans.push_back({arr[low], arr[high]});
                    }
                    low--;
                    high++;
                }
                else low--;
            }
        }
    }
    return ans;
}