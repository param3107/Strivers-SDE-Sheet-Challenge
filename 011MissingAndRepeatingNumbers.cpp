#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n){
    long long sum = 0, sqsum = 0;
	for(int i = 0; i < n; i++){
		sum += (long long) arr[i];
		sqsum += ((long long)arr[i])*((long long)arr[i]);
	}
	long long diff = (long long) (sum - (long long)n*(n+1)/2);
	long long sqdiff = (long long) (sqsum - (long long)n*(n+1)*(2*n + 1)/6);
	return make_pair((int)(sqdiff/diff - diff)/2, (int)(sqdiff/diff + diff)/2);
}