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
    if(head == NULL){
        n -> next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = n;
    n -> next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
    }
    node* n = new node(val);
    node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = n;
    n -> next = head;
}

void deleteAtHead(node* &head){
    node* temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    node* toDelete = head;
    temp -> next = head -> next;
    head = head -> next;
}


void deletion(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count != pos - 1){
        temp = temp -> next;   
        count++; 
    }
    node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete toDelete;
}

void display(node* head){
    node* temp = head;
    do{
        cout << temp -> data <<" ";
        temp = temp -> next;
    }while(temp != head);
    cout << endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    display(head);
    insertAtHead(head, 11);
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    display(head);
    deletion(head, 5);
    display(head);
    return 0;
}