#include <bits/stdc++.h>
using namespace std;

 class Node {
  public:
		int data;
		Node *next;
 		Node *child;
		Node() : data(0), next(nullptr), child(nullptr){};
		Node(int x) : data(x), next(nullptr), child(nullptr){}
		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
    };

Node* flattenLinkedList(Node* head){
    Node* key = new Node();
    key -> next = head;
    Node* currNode = head, *temp, *nextNode, *prevNode = key;
    bool flag = false;
    while(currNode != NULL){
        flag = false;
        temp = key;
        nextNode = currNode -> next;
        while(temp -> next != NULL){
            if(temp -> next -> data > currNode -> data){
                if(temp == currNode) break;
                prevNode -> next = nextNode;
                currNode -> next = temp -> next;
                temp -> next = currNode;
                flag = true;
                break;
            }   
            else temp = temp -> next;
        }
        if(!flag) prevNode = currNode;
        currNode = nextNode;
    }
    temp = key -> next;
    head = key -> next;
    Node *nextHead, *nextChild;
    while(temp != NULL){
        nextHead = temp -> next; 
        nextChild = temp -> child;
        if(nextHead !=NULL && nextChild != NULL){
            if(nextChild -> data <= nextHead -> data){
                temp -> next = NULL;
                temp = nextChild;
                temp -> next = nextHead;
            }
            else{
                Node* start = temp;
                Node* parent = temp;
                while(nextChild != NULL){
                    while((start -> next != NULL)){
                        if(start -> next -> data <= nextChild -> data){
                            start = start -> next;
                        }
                        else break;
                    }
                    if(start -> next == NULL){
                        parent -> child = NULL;
                        start -> next = nextChild;
                        break;
                    }
                    parent -> child = NULL;
                    nextChild -> next = start -> next;
                    start -> next = nextChild;
                    parent = nextChild;
                    nextChild = nextChild -> child;
                }
                temp -> child = nextHead;
                temp -> next = NULL;
                temp = temp -> child;
            }
        }
        else if(nextHead != NULL && nextChild == NULL){
            temp -> next = NULL;
            temp -> child = nextHead;
            temp = temp -> child;
        }
        else if(nextHead == NULL && nextChild != NULL){
            temp = nextChild;
        }
        else break;
    }
    return head;
}