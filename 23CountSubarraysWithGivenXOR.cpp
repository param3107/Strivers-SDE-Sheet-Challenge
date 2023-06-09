#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x){ // 5 3 8 3 10    8
    int XORsum = 0, count = 0;
    unordered_map<int, int> lookup;
    lookup[0] = 1;
    for(int i = 0; i < arr.size(); i++){
        XORsum ^= arr[i];
        count += lookup[XORsum^x];
        lookup[XORsum]++;
    }
    return count;
}