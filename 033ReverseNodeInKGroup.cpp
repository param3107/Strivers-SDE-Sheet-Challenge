#include <bits/stdc++.h>
using namespace std;

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

Node* blockReverse(Node* start, int n){
    if(!n) return start;
    else if(n == 1){
        return start -> next;
    }
    n--;
    Node *head = start -> next, *prev = head, *mid = head -> next, *end = head -> next;
    while(mid != NULL && n){
        end = end -> next;
        mid -> next = prev;
        prev = mid;
        mid = end;
        n--;
    }
    start -> next = prev;
    head -> next = end;
    return head;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head == NULL || head -> next == NULL) return head;
    Node* start = new Node(-1);
    start -> next = head;
    head = blockReverse(start, b[0]);
    if(head -> next == NULL) return start -> next;
    for(int i = 1; i < n; i++){
        head = blockReverse(head, b[i]);
        if(head -> next == NULL) break;
    }
    return start -> next;
}