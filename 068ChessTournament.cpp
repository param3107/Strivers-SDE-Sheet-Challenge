#include <bits/stdc++.h> 
using namespace std;

bool isValid(int minFocus, vector<int> &positions, int c){
    int count = 1;
    int prev = positions[0];
    for(int i = 0; i < positions.size(); i++){
        if(positions[i] - prev >= minFocus){
            prev = positions[i];
            count++;
        }
    }
    return count >= c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
    int low = 1, high = (positions[n-1] - positions[0] - 1)/(c-1);
    int ans;
    while(low <= high){
        int mid = (low + high)/2;
        if(isValid(mid, positions, c)){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}