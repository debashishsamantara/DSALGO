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

Node* sortedArrToBST(int arr[], int start, int end){
    if(start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root -> left = sortedArrToBST(arr, start, mid - 1);
    root -> right = sortedArrToBST(arr, mid + 1, end);
    return root;
}

void printPreorder(Node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    Node* root = sortedArrToBST(arr, 0, 7);
    printPreorder(root);
    cout << endl; 
    return 0;
}