#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void func(string &s, string word){
    s += "|" + word;
    cout << s << endl;
    s = s.substr(0, s.length() - word.length() - 1);
}
int main(){
    int* arr;
    arr = new int[10];
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    } cout << endl;
}