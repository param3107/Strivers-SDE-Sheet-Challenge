#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int low = 0, high = s.length()-1;
    while(low <= high) if(s[low++] != s[high--]) return false;
    return true;
}

void func(vector<vector<string>> &ans, vector<string> &currArr, string s){
    if(s.length() == 0){
        ans.push_back(currArr);
        return;
    }
    for(int i = 1; i <= s.length(); i++){
        if(isPalindrome(s.substr(0, i))){
            currArr.push_back(s.substr(0, i));
            func(ans, currArr, s.substr(i));  
            currArr.pop_back();  
        }
    }
    return;
}

vector<vector<string>> partition(string &s){
    vector<vector<string>> ans;
    vector<string> currArr{};
    func(ans, currArr, s);
    return ans;
}