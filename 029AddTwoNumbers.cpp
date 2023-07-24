#include <bits/stdc++.h>
using namespace std;

  class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node *next) {
           this->data = data;
           this->next = next;
       }
  };
 

Node *addTwoNumbers(Node *num1, Node *num2){
    Node* temp = num1;
    Node* head = num1;
    int carry = 0, sum = 0;
    while(num1 != NULL && num2 != NULL){
        sum = (num1 -> data + num2 -> data + carry)%10;
        carry = (num1 -> data + num2 -> data + carry)/10;
        temp -> data = sum;
        num1 = num1 -> next;
        num2 = num2 -> next;
        if(num1 != NULL) temp = temp -> next;
        else if(num1 == NULL && num2 != NULL){
            temp -> next = num2;
            temp = num2;
        }
    }
    while(num1 != NULL){
        sum = (num1 -> data + carry)%10;
        carry = (num1 -> data + carry)/10;
        temp -> data = sum;
        num1 = num1 -> next;
        if(num1 != NULL) temp = temp -> next;
    }
    while(num2 != NULL){
        sum = (num2 -> data + carry)%10;
        carry = (num2 -> data + carry)/10;
        temp -> data = sum;
        num2 = num2 -> next;
        if(num2 != NULL) temp = temp -> next;
    }
    if(carry){
        temp -> next = new Node(carry);
    }
    return head;
}
