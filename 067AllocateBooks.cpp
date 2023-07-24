#include <bits/stdc++.h> 
using namespace std;

bool isValid(int n, int m,vector<int> time,long long limit){
    int count = 1;
    long long sum = 0;
    for(int i=0;i<m;i++){
        if(sum + time[i] <= limit)
          sum+=time[i];
        else{
            count++;
            sum=time[i];
        }
    }
    return  (count <= n);
}

long long ayushGivesNinjatest(int n, int m, vector<int> time){	
	long long total = 0;
	int Max = INT_MIN;
	for(int i = 0; i < m; i++){
		Max = max(Max, time[i]);
		total += time[i];
	}
	long long low = Max, high = total;
	long long ans = 0;
    while(low <= high){
		long long mid = (low + high)/2;
        if(isValid(n, m, time, mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
	}
    return ans;
}
