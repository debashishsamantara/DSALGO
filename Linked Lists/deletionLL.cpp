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

void deleteAtHead(node* &head){
    node* toDelete = head;
    head = head -> next;
    delete toDelete;
}

void deletion(node* &head, int val){
    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete toDelete;
}

int main(){
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    display(head);
    deletion(head, 3);
    deleteAtHead(head);
    display(head);
    return 0;
}