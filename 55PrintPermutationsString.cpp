#include <bits/stdc++.h> 
using namespace std;

void permutation(int index, string &s, vector<string> &ansVect){
    if(index == s.length()){
        ansVect.push_back(s);
        return;
    }
    for(int i = index; i < s.length(); i++){
        swap(s[index], s[i]);
        permutation(index + 1, s, ansVect);
        swap(s[index], s[i]);
    }
    return;

}

vector<string> findPermutations(string &s){
    vector<string> ansVect;
    permutation(0, s, ansVect);
    return ansVect;
}