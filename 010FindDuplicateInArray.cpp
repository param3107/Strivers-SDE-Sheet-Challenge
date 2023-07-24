#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	int index[n] = {0};
    for(int i = 0; i < n; i++){
        index[arr[i]]++;
        if(index[arr[i]] > 1) return arr[i];
    }
}
