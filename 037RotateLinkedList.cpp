#include <bits/stdc++.h>
using namespace std;

 class Node {
 public:
     int data;
     Node *next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
 };

Node *rotate(Node *head, int k) {
    if(!k) return head;
    Node* temp = head;
    int count = 1;
    while(temp -> next != NULL){
        temp = temp -> next;
        count++;
    }
    temp -> next = head;
    k = k % count;
    temp = head;
    for(int i = 0; i < count - k - 1; i++){
        temp = temp -> next;
    }
    Node* end = temp;
    Node* start = temp -> next;
    end -> next = NULL;
    return start;
}