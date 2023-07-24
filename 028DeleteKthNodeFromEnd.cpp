#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* removeKthNode(Node* head, int K){
    if(head == NULL){
        return head;
    }
    Node* last = head;
    Node* temp = head;
    Node* bumper = head;
    for(int i = 0; i < K-1; i++){
        bumper = bumper -> next;
        if(bumper == NULL) return head;
    }
    while(bumper -> next != NULL){
        bumper = bumper -> next;
        last = temp;
        temp = temp -> next;
    }
    if(temp == head){
        head = head -> next;
    }
    else last -> next = temp -> next;
    return head;
}