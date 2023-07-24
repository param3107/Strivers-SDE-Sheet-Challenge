#include <bits/stdc++.h>
#include <unordered_set>
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


Node* findIntersection(Node *firstHead, Node *secondHead){
    int len1 = 1, len2 = 1;
    Node* temp = firstHead;
    while(temp != NULL){
        temp = temp -> next;
        len1++;
    }
    temp = secondHead;
    while(temp != NULL){
        temp = temp -> next;
        len2++;
    }
    int difference = (len1 > len2) ? len1 - len2 : len2 - len1;
    if(len1 > len2){
        for(int i = 0; i < difference; i++) firstHead = firstHead -> next;
    }
    else for(int i = 0; i < difference; i++) secondHead = secondHead -> next;
    while(firstHead != NULL){
        if(firstHead == secondHead) return firstHead;
        firstHead = firstHead -> next;
        secondHead = secondHead -> next;
    }
    return NULL;
}