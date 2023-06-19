#include <bits/stdc++.h>
using namespace std;

    // template <typename T>   
    // class LinkedListNode
    // {
    //     public:
    //     T data;
    //     LinkedListNode<T> *next;
    //     LinkedListNode<T> *random;
    //     LinkedListNode(T data)
    //     {
    //         this->data = data;
    //         this->next = NULL;
    //     }
    // };

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head){
    if(head == NULL) return head;
    LinkedListNode<int>* temp = head, *nextNoad;
    while(temp != NULL){
        nextNoad = temp -> next;
        temp -> next = new LinkedListNode<int>(temp -> data);
        temp -> next -> next = nextNoad;
        temp = nextNoad;
    }
    temp = head;
    while(temp != NULL){
        if(temp -> random != NULL) temp -> next -> random = temp -> random -> next;
        else temp -> next -> random = NULL;
        temp = temp -> next -> next;
    }
    temp = head;
    LinkedListNode<int> *newHead = new LinkedListNode<int>(0);
    LinkedListNode<int> *copier = newHead;
    while(temp != NULL){
        nextNoad = temp -> next -> next;
        copier -> next = temp -> next;
        copier = copier -> next;
        temp -> next = nextNoad;
        temp = nextNoad;
    }
    return newHead -> next;
}
