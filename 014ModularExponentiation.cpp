#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(long long x, long long n, long long m) {
	long long ans = 1;

    while(n > 0){
		if(n % 2 != 0){
			ans = ((ans % m) * (x % m)) % m;
			n--;
		}
		else{
			x = ((x % m) * (x % m)) % m;
			n = n/2;
		}  
    }
    return ans;
}