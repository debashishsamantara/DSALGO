#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inOrder[], int start, int end, int curr){
    for(int i = 0; i <= end; i++){
        if(inOrder[i] == curr)
            return i;
    }
    return -1;
}

Node* buildTree(int postOrder[], int inOrder[], int start, int end){
    static int idx = end;
    if(start > end)
        return NULL;
    int val = postOrder[idx];
    idx--;
    Node* curr = new Node(val);
    if(start == end)
        return curr;
    int pos = search(inOrder, start, end, val);
    curr -> right = buildTree(postOrder, inOrder, pos+1, end);
    curr -> left = buildTree(postOrder, inOrder, start, pos-1);
    return curr;
}

void inOrderPrint(Node* root){
    if(root == NULL)
        return;
    inOrderPrint(root -> left);
    cout << root -> data << " ";
    inOrderPrint(root -> right);
}


int main(){
    int postOrder[] = {4, 2, 5, 3, 1};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node* root = buildTree(postOrder, inOrder, 0, 4);
    inOrderPrint(root);
    return 0;
}