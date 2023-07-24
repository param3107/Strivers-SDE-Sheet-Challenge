#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input){ //ababcdede
    int maxLength = 1, length = 0;
    int start = 0;
    int lookup[26];
    for(int i = 0; i < 26; i++) lookup[i] = -1; 
    for(int i = 0; i < input.length(); i++){
        if(lookup[input[i] - 'a'] != -1) start = max(lookup[input[i] - 'a'] + 1, start);
        lookup[input[i] - 'a'] = i;
        maxLength = max(maxLength, (i - start + 1));
    }
    return maxLength;
}
