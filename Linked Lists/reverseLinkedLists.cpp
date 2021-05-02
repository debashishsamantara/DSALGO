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

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp -> data <<"->";
        temp = temp -> next;
    }cout << "NULL" <<endl;
}

//ITERATIVE WAY OF REVERSING
node* reverse(node* &head){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    while(currPtr != NULL){
        nextPtr = currPtr -> next;
        currPtr -> next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

//RECURSIVE WAY OF REVERSING
node* reverseRecursive(node* &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    node* newHead = reverseRecursive(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}


int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    node* newHead;
    newHead = reverseRecursive(head);
    display(newHead);
    return 0;
}