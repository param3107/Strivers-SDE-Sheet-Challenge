#include <math.h>

int NthRoot(int n, int m) {
    int low = 0, high = m;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(pow(mid, n) == m) return mid;
        else if(high == low) return -1;
        else if(high - low == 1 && pow(high, n) != m) return -1;
        else if(pow(mid, n) > m) high = mid-1;
        else{
            low = mid+1;
        } 
    }
}