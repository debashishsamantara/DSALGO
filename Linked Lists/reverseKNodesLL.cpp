#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n -> next = head;
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data <<"->";
        temp = temp -> next;
    }cout << "NULL" <<endl;
}

node* reverseK(node* &head, int k){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    int count = 0;
    while(currPtr != NULL && count < k){
        nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;    
    }
    if(nextPtr != NULL){
        head -> next = reverseK(nextPtr, k);
    }
    return prevPtr;
}

int main(){
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    display(head);
    node* newHead = reverseK(head, 2);
    display(newHead);
    return 0;
}