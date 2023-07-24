#include <bits/stdc++.h> 
using namespace std;

void generate(vector<string> &ans, string sentence, string word, string s, unordered_map<string, bool> &lookup){
    cout << sentence << "|" << word << "|" << s << endl;
    if(word == "" && s == ""){
        ans.push_back(sentence);
        return;
    }
    if(lookup[word]){
        generate(ans, sentence + " " + word, "", s, lookup);
        generate(ans, sentence, word + s[0], s.substr(1), lookup);
        return;
    }
    if(s != ""){
        generate(ans, sentence, word + s[0], s.substr(1), lookup);
        return;
    }
    return;
}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    unordered_map<string, bool> lookup;
    vector<string> ans;
    for(int i = 0; i < dictionary.size(); i++){
        lookup[dictionary[i]] = true;
    }
    generate(ans, "", "", s, lookup);
    return ans;
}