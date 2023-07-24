#include <bits/stdc++.h> 

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


bool isPalindrome(LinkedListNode<int> *head){
    if(head == NULL || head -> next == NULL) return true;
    LinkedListNode<int> *prev = NULL, *mid = head, *end = head, *bumper = head;
    bool flag = true;
    while(bumper != NULL){
        bumper = bumper -> next;
        if(flag){    
            end = end -> next;
            if(bumper == NULL) break;
            mid -> next = prev;
            prev = mid;
            mid = end;
        }
        flag = !flag;
    }
    while(prev -> data == end -> data){
        prev = prev -> next;
        end = end -> next;
        if(prev == NULL && end == NULL) return true;
        else if((prev != NULL) != (end != NULL)) return false;
    }
    return false;
}