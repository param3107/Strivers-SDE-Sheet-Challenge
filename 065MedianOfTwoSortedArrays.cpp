#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b){
    if(a.size() > b.size()) return median(b, a);
    
    int m = a.size();
    int n = b.size();
    int low = 0, high = m, median=((m+n)+1)/2;
    while(low <= high){
        int m1 = (low + high)/2;
        int m2 = median - m1;
        
        int l1 = (m1 == 0) ? INT_MIN : a[m1-1];
        int l2 = (m2 == 0) ? INT_MIN : b[m2-1];
        int r1 = (m1 == m) ? INT_MAX : a[m1];
        int r2 = (m2 == n) ? INT_MAX : b[m2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = m1-1;
        else low = m1+1;
    }
    return 0.0;
}