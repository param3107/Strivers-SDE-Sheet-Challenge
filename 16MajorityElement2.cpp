// Extended Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr){
    vector<int> ans;
    int count1 = 0, count2 = 0, element1, element2;
    for(int i = 0; i < arr.size(); i++){
        if(count1 == 0 && arr[i] != element2){
            count1++;
            element1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != element1){
            count2++;
            element2 = arr[i];
        }
        else if(arr[i] == element1) count1++;
        else if(arr[i] == element2) count2++;
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == element1) count1++;
        else if(arr[i] == element2) count2++;
    }
    if(count1 > arr.size()/3) ans.push_back(element1);
    if(count2 > arr.size()/3) ans.push_back(element2);
    return ans;
}