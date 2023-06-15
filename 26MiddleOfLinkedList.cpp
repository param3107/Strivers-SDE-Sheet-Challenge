#include <bits/stdc++.h>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node()
//     {
//         this->data = 0;
//         next = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data; 
//         this->next = NULL;
//     }
//     Node(int data, Node* next)
//     {
//         this->data = data;
//         this->next = next;
//     }
// };


Node *findMiddle(Node *head){
    Node* middle = head;
    Node* temp = head;
    bool flag = true;
    while(temp -> next != NULL){
        temp = temp -> next;
        if(flag){
            middle = middle -> next;
        }
        flag = !flag;
    }
}

