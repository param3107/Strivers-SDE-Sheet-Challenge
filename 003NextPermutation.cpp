#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n){
    for(int i = n-1; i > 0; i--){
        if(permutation[i] > permutation[i-1]){
            int Xi = i-1;
            int X = permutation[i-1];
            while((X < permutation[i]) && (i < n)){
                i++;
            } i--;
            swap(permutation[Xi], permutation[i]);
            reverse(permutation.begin() + (Xi+1), permutation.end());
            return permutation;
        }
    }
    reverse(permutation.begin(), permutation.end());
    return permutation;
}