#include <bits/stdc++.h>
using namespace std;

template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head){
    if(head == NULL) return head;
    LinkedListNode<int>* last = head;
    LinkedListNode<int>* temp = head -> next;
    LinkedListNode<int>* mid = head -> next;
    last -> next = NULL;
    while(temp != NULL){
        temp = temp -> next;
        mid -> next = last;
        last = mid;
        mid = temp;
    }
    return last;
}