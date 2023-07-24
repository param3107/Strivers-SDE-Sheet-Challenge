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


Node *firstNode(Node *head){
    if(head == NULL) return NULL;
    Node* slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            fast = head;
            while(slow -> next != fast -> next){
                slow = slow -> next;
                fast = fast -> next;
            }
            return fast -> next;
        }
    }
    return NULL;
}