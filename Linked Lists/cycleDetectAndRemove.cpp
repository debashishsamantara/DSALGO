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

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow)
                return true;
    }    
    return false;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    int count = 1;
    while (temp -> next != NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp -> next;
        count++;
    }
    temp -> next = startNode;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast);
    fast = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = NULL;
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
    makeCycle(head, 3);
    cout << detectCycle(head);
    removeCycle(head);
    cout << detectCycle(head);
    display(head);
    return 0;
}