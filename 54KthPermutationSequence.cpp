#include <bits/stdc++.h>
using namespace std;

void func(string &ans, int (&facts)[10], vector<int> &num, int k){
    if(k == 0){
        for(int i = num.size()-1; i >= 0; i--){
            ans += to_string(num[i]);
        }
        return;
    }
    int x = (int) ceil((double) k/facts[(num.size()-1)])-1;
    ans += to_string(num[x]);
    k = k % facts[(num.size()-1)];
    num.erase(num.begin() + x);
    func(ans, facts, num, k);
    return;
}

string kthPermutation(int n, int k) {
    int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    string ans = "";
    vector<int> num {};
    for(int i = 1; i <=n; i++){
        num.push_back(i);
    }
    func(ans, facts, num, k);
    return ans;
}
