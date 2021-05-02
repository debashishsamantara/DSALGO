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

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == key){
            return key;
        }
        temp = temp -> next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    display(head);
    cout << search(head, 3) << endl;
    return 0;
}