#include <bits/stdc++.h>
using namespace std;

    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    
    if(first == NULL && second == NULL) return first;
    else if (first == NULL) return second;
    else if (second == NULL) return first;
    Node<int>* head = ((first -> data) <= (second -> data)) ? first : second;
    if(head == first) first = first -> next;
    else second = second -> next;
    Node<int>* temp = head;
    while(first != NULL && second != NULL){
        if(first -> data <= second -> data){
            temp -> next = first;
            temp = first;
            first = first -> next;
        }
        else{
            temp -> next = second;
            temp = second;
            second = second -> next;
        }
    }
    while(first != NULL){
        temp -> next = first;
        temp = first;
        first = first -> next;
    }
    while(second != NULL){
        temp -> next = second;
        temp = second;
        second = second -> next;
    }
    return head;
}
