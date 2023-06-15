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

bool detectCycle(Node *head){
    bool ans = false;
	while(head != NULL){
        head -> data = -1;
        head = head -> next;
        if(head -> data == -1){
            ans = true;
            break;
        }
    }
    return ans;
}